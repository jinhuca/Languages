/*
 *  C# Design Pattern Essentials
 *  Copyright 2012, Ability First Limited
 *
 *  This source code is provided to accompany the book and is provided AS-IS without warranty of any kind.
 *  It is intended for educational and illustrative purposes only, and may not be re-published
 *  without the express written permission of the publisher.
 */
using System;

namespace D16_Iterator
{
    public abstract class AbstractVehicle : IVehicle
    {
        private IEngine engine;
        private VehicleColor _color;

        public AbstractVehicle(IEngine engine)
            : this(engine, VehicleColor.Unpainted)
        {
        }

        public AbstractVehicle(IEngine engine, VehicleColor color)
        {
            this.engine = engine;
            this._color = color;
        }

        public virtual IEngine Engine
        {
            get
            {
                return engine;
            }
        }

        public virtual VehicleColor Color
        {
            get
            {
                return _color;
            }
        }

        public virtual void Paint(VehicleColor color)
        {
            this._color = color;
        }

        public override string ToString()
        {
            return this.GetType().Name + " (" + engine + ", " + _color + ")";
        }

    }

}
