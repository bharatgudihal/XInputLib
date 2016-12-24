using System.Runtime.InteropServices;
using System.Reflection;
using System;

namespace XInputWrapper
{
    public class Wrapper
    {

        [DllImport("XInputLib")]
        public static extern bool VibrateRight(uint controllerIndex, float intensity);

        [DllImport("XInputLib")]
        public static extern bool VibrateLeft(uint controllerIndex, float intensity);
                
    }
}
