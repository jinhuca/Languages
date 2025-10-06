﻿/*
 *  C# Design Pattern Essentials
 *  Copyright 2012, Ability First Limited
 *
 *  This source code is provided to accompany the book and is provided AS-IS without warranty of any kind.
 *  It is intended for educational and illustrative purposes only, and may not be re-published
 *  without the express written permission of the publisher.
 */

namespace D12_Proxy
{
    public abstract class AbstractEngine : IEngine
    {

        private int size;
        private bool turbo;


        public AbstractEngine(int size, bool turbo)
        {
            this.size = size;
            this.turbo = turbo;
        }

        public virtual int Size
        {
            get
            {
                return size;
            }
        }

        public virtual bool Turbo
        {
            get
            {
                return turbo;
            }
        }

        public virtual void Diagnose(IDiagnosticTool tool)
        {
            tool.RunDiagnosis(this);
        }


        public override string ToString()
        {
            return GetType().Name + " (" + size + ")";
        }

    }
}
