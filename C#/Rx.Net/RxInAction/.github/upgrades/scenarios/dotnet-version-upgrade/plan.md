# .NET 10 Upgrade Plan

## Overview

**Target**: Upgrade all 92 projects in the RxInAction solution from mixed frameworks (net8.0, net9.0, net10.0) to .NET 10 (net10.0)

**Scope**: Large solution with diverse project types:
- 92 total projects
- Currently targeting net8.0 (~50 projects), net9.0 (~38 projects), net10.0 (~4 projects already)
- Includes WPF applications, console apps, class libraries
- All SDK-style modern .NET projects (no legacy .csproj format)
- Known issues: ~20 projects with API incompatibilities, multiple deprecated NuGet packages

**Strategy**: All-at-Once atomic upgrade — all projects updated together, validated holistically

## Tasks

### 01-prerequisites: Validate environment and prepare for upgrade

Ensure the development environment is ready for the .NET 10 upgrade. Verify that the .NET 10 SDK is installed, compatible tooling is available, and the solution can be loaded without errors. This is a gate task — validation failures here must be resolved before proceeding to framework upgrades.

**Done when**: 
- .NET 10 SDK confirmed installed and available
- Visual Studio or dotnet CLI tooling verified
- Solution loads without errors
- Baseline build succeeds (before framework changes)

---

### 02-framework-upgrade-all-projects: Update project files to target .NET 10

Upgrade all 92 projects to .NET 10 by updating target framework in project files. This includes projects currently on net8.0 and net9.0, as well as the 4 projects already on net10.0 (verify they are already correct). Handle multi-targeting scenarios (e.g., WPF projects with platform-specific targets like `net10.0-windows`) appropriately.

For projects with platform-specific TFMs (WPF projects with `-windows`, etc.), ensure the primary target becomes `net10.0` (or `net10.0-windows` for WPF/Windows-specific projects).

**Affected items**: All 92 projects across AppendixA, AppendixB, AppendixC, C01-C11, Events, Common, captured as csproj files

**Known concerns**:
- 4 WPF projects require `net10.0-windows` targets: P100, P154, P195DistinctUntilChanged, P251ObserveOnDispatcher
- Some projects may have platform-specific dependencies
- Verify that no project is left with the old framework after this task

**Done when**:
- All 92 projects have TargetFramework set to net10.0 (or net10.0-windows for WPF)
- No projects remain targeting net8.0 or net9.0
- Solution file consistency verified (no mixed frameworks remain)

---

### 03-nuget-package-updates: Update packages to versions supporting .NET 10

Address NuGet package compatibility. Many projects reference deprecated packages or versions incompatible with .NET 10. Update packages to versions that support the target framework, or identify and remove packages that are no longer needed.

**Assessment context**:
- ~35+ projects have deprecated packages (NuGet.0005 issues)
- Some packages now included in framework (NuGet.0003 issues for P185BasicQueryOperators)
- Ensure all package versions are compatible with net10.0

**Known packages requiring updates**:
- Multiple projects with deprecated packages in AppendixB, C04, C06, C07, C08, and others
- Framework now includes some functionality previously from packages

**Research starting points**:
- Check each deprecated package for a newer version supporting net10.0
- Review packages marked as \u0022functionality now in framework\u0022 to determine if package can be removed safely
- Validate that updates don't break existing dependencies

**Done when**:
- All deprecated packages either updated to net10.0-compatible versions or documented as intentionally retained
- Checks complete for packages marked \u0022functionality now in framework\u0022
- Full solution NuGet restore succeeds without warnings for compatibility

---

### 04-address-api-incompatibilities: Fix source and binary API breaks

Address breaking changes identified in the assessment. Several projects have API incompatibilities requiring code changes:

**Affected projects with source incompatibilities (Api.0002)**: 
- C0103.AsyncDemo, C0500.Threads, C0501.ThreadAsync, Helpers
- P121, P141, P142, P143, P161, P167, P170, P173
- P234Schedulers, P242, P251ObserveOnDispatcher, P252, P278

**Affected projects with binary incompatibilities (Api.0001)**:
- P100, P154, P251ObserveOnDispatcher

**Behavioral changes to verify (Api.0003)**:
- A0104, C0501.ThreadAsync, P100, P154, P251ObserveOnDispatcher

**Research starting points**:
- Check WPF projects (P100, P154, P195, P251) for UI framework changes between net9 and net10
- Review Threading changes in C0500, C0501, and related projects
- Investigate disposal patterns and IDisposable changes if present

**Done when**:
- All source incompatibilities resolved (code compiles against net10.0 APIs)
- All binary incompatibilities addressed (updated to newer API surface)
- Behavioral changes verified and code adapted if needed
- Solution compiles without errors

---

### 05-integration-validation: Validate solution integrity and run tests

Final validation that the upgrade is complete and functional. Build the entire solution, run all available tests, and verify no regressions were introduced.

**Validation checks**:
- Full solution build succeeds
- All projects compile without warnings
- Unit tests pass
- Integration tests pass
- Verify no deprecated APIs remain in code
- Spot-check that WPF and platform-specific projects run correctly

**Done when**:
- Full solution builds without errors or warnings
- All automated tests pass
- Manual verification of critical functionality complete
- No integration issues detected

---

## Strategy Declaration

**Strategy**: All-at-Once
**Approach**: Atomic upgrade of all 92 projects together to .NET 10
**Rationale**: All projects are already on modern .NET (net8.0, net9.0). No legacy framework migration needed. Upgrading atomically keeps all dependencies in sync and ensures holistic validation.
**Commit Strategy**: Single commit at the end of all tasks for atomic history
