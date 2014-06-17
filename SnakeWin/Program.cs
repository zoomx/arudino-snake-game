using System;
using System.Collections.Generic;
using System.Text;
using System.IO.Ports;
using System.Threading;
using System.Diagnostics;
using System.Windows.Forms;

/* If you receive a Loader lock error do the following:
 * 
 *  go to menu Debug -> Exceptions, open the Managed Debugging Assistants, find LoaderLock and uncheck
 */
namespace SnakeWin
{
    class Program
    {
        private static SerialPort _sp = new SerialPort();
        private static JoystickInterface.Joystick _jst;
        private static string _lastKey = "";
        private static string _sendingKey = "";

        static void Main(string[] args)
        {
            setupJoystick();
            init();
            read();
        }

        static void setupJoystick()
        {
            _jst = new JoystickInterface.Joystick(Process.GetCurrentProcess().MainWindowHandle);
            string[] sticks = _jst.FindJoysticks();
            _jst.AcquireJoystick(sticks[0]);
        }

        static void init()
        {
            _sp.DataReceived += new SerialDataReceivedEventHandler(DataReceivedHandler);
            _sp.PortName = "COM7";
            Console.Write("Connecting... ");   
            do
            {
                try
                {
                    _sp.Open();
                    Thread.Sleep(500);
                }
                catch
                {}
                   
            }
            while (!_sp.IsOpen);

            Console.WriteLine("Connected!");   
        }

        static void read()
        {

           

            while (true){

                _jst.UpdateStatus();

                if ((_lastKey != "Z") && (_sendingKey == "") && (KeyboardInfo.GetKeyState(Keys.Z).IsPressed || (_jst.AxisC < 32767)))
                {
                    _lastKey = "Z";
                    _sendingKey = "Z";
                    _sp.Write("Z");
                  }
                  else if ((_lastKey != "X") && (_sendingKey == "") && (KeyboardInfo.GetKeyState(Keys.X).IsPressed || (_jst.AxisC > 32767)))
                {
                    _lastKey = "X";
                    _sendingKey = "X";
                    _sp.Write("X");
                }
                else if (!(_jst.AxisC < 32767) && !(_jst.AxisC > 32767))
                {
                    _lastKey = "";
                }
                else if (KeyboardInfo.GetKeyState(Keys.Escape).IsPressed)
                {
                    break;
                }

                Application.DoEvents();
            }
            Console.WriteLine("Exit!");  
        }

        private static void DataReceivedHandler(object sender, SerialDataReceivedEventArgs e)
        {
            SerialPort sp = (SerialPort)sender;
            string indata = sp.ReadExisting();
            Console.WriteLine("Received: " + indata);

            //if (indata == Environment.NewLine)
            if (_sendingKey == indata)
                _sendingKey = "";
        }


    }
}
