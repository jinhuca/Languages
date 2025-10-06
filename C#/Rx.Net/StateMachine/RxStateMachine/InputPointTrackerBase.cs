﻿namespace RxStateMachine;

public class InputPointTrackerBase : IInputPointTracker
{
  private readonly List<object> _activePoints = new List<object>();

  private readonly object _activePointsLocker = new object();

  public virtual void Track(EventArgs e)
  {

  }

  protected void AddPoint(object point)
  {
    ArgumentNullException.ThrowIfNull(point);

    lock(_activePointsLocker)
    {
      if(_activePoints.Count == 0)
        _initial = point;

      _activePoints.Add(point);
    }
  }

  protected void RemovePoint(object point)
  {
    ArgumentNullException.ThrowIfNull(point);

    lock(_activePointsLocker)
    {
      _activePoints.Remove(point);
    }
  }

  private object _initial;

  public int Count
  {
    get
    {
      lock(_activePointsLocker)
        return _activePoints.Count;
    }
  }

  public bool Contains(object point)
  {
    if(point == null)
      throw new ArgumentNullException(nameof(point));

    lock(_activePointsLocker)
      return _activePoints.Contains(point);
  }

  public bool First(object point)
  {
    ArgumentNullException.ThrowIfNull(point);

    lock(_activePointsLocker)
      return _activePoints.FirstOrDefault() == point;
  }

  public bool Initial(object point)
  {
    ArgumentNullException.ThrowIfNull(point);

    lock(_activePointsLocker)
      return _initial == point;
  }

  public bool Intermediate(object point)
  {
    ArgumentNullException.ThrowIfNull(point);

    lock(_activePointsLocker)
      return _activePoints.FirstOrDefault() != point && _activePoints.LastOrDefault() != point && _activePoints.Contains(point);
  }

  public bool Subsequent(object point)
  {
    ArgumentNullException.ThrowIfNull(point);

    lock(_activePointsLocker)
      return _activePoints.Contains(point) && _activePoints.FirstOrDefault() != point;
  }

  public bool Last(object point)
  {
    ArgumentNullException.ThrowIfNull(point);

    lock(_activePointsLocker)
      return _activePoints.LastOrDefault() == point;
  }

  public bool AtPosition(object point, int position)
  {
    ArgumentNullException.ThrowIfNull(point);

    lock(_activePointsLocker)
      return _activePoints.ElementAtOrDefault(position) == point;
  }

  public object[] ActivePoints
  {
    get
    {
      lock(_activePointsLocker)
        return _activePoints.ToArray();
    }
  }
}