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
    public class Saloon : AbstractCar
    {

        public Saloon(IEngine engine)
            : this(engine, VehicleColor.Unpainted)
        {
        }

        public Saloon(IEngine engine, VehicleColor color)
            : base(engine, color)
        {
        }

    }
}
