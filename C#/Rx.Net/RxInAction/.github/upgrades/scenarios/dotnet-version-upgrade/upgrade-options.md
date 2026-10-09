# Upgrade Options

## Strategy

| Strategy | Description | Selection | Why |
|----------|-------------|-----------|-----|
| **All-at-Once** | Upgrade all projects together in a single pass. All projects move from their current frameworks to .NET 10 atomically. Best for solutions where dependencies are well-tested and changes can be validated holistically. | **All-at-Once** (selected) | Solution has 92 projects across net8.0, net9.0, and net10.0. All are modern .NET with SDK-style projects. No .NET Framework legacy to migrate. Single atomic upgrade minimizes coordination complexity and ensures all projects reach the same target together. |
| Bottom-Up | Upgrade dependencies first (bottom tier), gradually working up to leaf projects (top tier). Useful for solutions with complex multi-tier architectures where lower-level changes need validation before upper-level changes are attempted. | Not selected | Not the best fit for this solution's structure. |
| Top-Down | Upgrade applications first (top tier), then libraries (bottom tier). Useful when applications drive requirements and libraries need to adapt. | Not selected | Not the best fit for this solution's structure. |

