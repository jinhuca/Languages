namespace D06Adapter
{
    public class SuperGreenEngineAdapter : AbstractEngine
    {
        public SuperGreenEngineAdapter(SuperGreenEngine greenEngine)
            : base(greenEngine.EngineSize, false)
        {
        }
    }
}
