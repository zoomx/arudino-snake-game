using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;

// http://crazorsharp.blogspot.co.uk/2009/05/when-keypressed-keydown-just-isnt.html
namespace SnakeWin
{
    public struct KeyStateInfo
    {
        private Keys key;
        private bool isPressed;
        private bool isToggled;

        public KeyStateInfo(Keys key, bool ispressed, bool istoggled)
        {
            this.key = key;
            isPressed = ispressed;
            isToggled = istoggled;
        }

        public static KeyStateInfo Default
        {
            get
            {
                return new KeyStateInfo(Keys.None, false, false);
            }
        }

        public Keys Key
        {
            get { return key; }
        }

        public bool IsPressed
        {
            get { return isPressed; }
        }

        public bool IsToggled
        {
            get { return isToggled; }
        }
    }
}
