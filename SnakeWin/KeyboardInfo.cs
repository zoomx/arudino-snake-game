using System;
using System.Collections.Generic;
using System.Text;

// http://crazorsharp.blogspot.co.uk/2009/05/when-keypressed-keydown-just-isnt.html
namespace SnakeWin
{
    using System;
    using System.Windows.Forms;
    using System.Runtime.InteropServices;

    public class KeyboardInfo
    {
        private KeyboardInfo() { }
        [DllImport("user32")]
        private static extern short GetKeyState(int vKey);

        public static KeyStateInfo GetKeyState(Keys key)
        {
            short keyState = GetKeyState((int)key);
            int low = Low(keyState), high = High(keyState);
            bool toggled = low == 1;
            bool pressed = high == 1;
            return new KeyStateInfo(key, pressed, toggled);
        }
        private static int High(int keyState)
        {
            return keyState > 0 ? keyState >> 0x10
                    : (keyState >> 0x10) & 0x1;
        }
        private static int Low(int keyState)
        {
            return keyState & 0xffff;
        }
    }
}
