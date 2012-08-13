using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.IO.Ports;
using System.Text.RegularExpressions;
using System.Net.Sockets;
using System.IO;
using System.Net;
using System.Threading;


namespace SerialportSample
{
    public partial class SerialportSampleForm : Form
    {
        private SerialPort comm = new SerialPort();
        private StringBuilder builder = new StringBuilder();
        private long received_count = 0;
        private long send_count = 0;
        private TcpListener tcpServerListener;
        private delegate void TextBoxDelegate(object item);
        private delegate void TextBoxDelegate1(object item);
        private delegate void SendBoxDelegate(object item);
        private delegate void CheckBoxDelegate();
        private delegate string GetBoxDelegate();
        public Socket serverSocket;
        string returnMsg;
        byte[] byteData = new Byte[255];
        bool FLAG;
        public SerialportSampleForm()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            string[] ports = SerialPort.GetPortNames();
            Array.Sort(ports);
            comboPortName.Items.AddRange(ports);
            comboPortName.SelectedIndex = comboPortName.Items.Count > 0 ? 0 : -1;
            comboBaudrate.SelectedIndex = comboBaudrate.Items.IndexOf("9600");

            comm.NewLine = "\r\n";
            comm.RtsEnable = true;

            comm.DataReceived += comm_DataReceived;
            this.button2.Enabled = false;
        }

        private void CTextBox(object item)
        {
            if (this.comboBaudrate.InvokeRequired)
            {
                // This is a worker thread so delegate the task.
                this.comboBaudrate.Invoke(new TextBoxDelegate(this.CTextBox), item);
            }
            else
            {
                // This is the UI thread so perform the task.
                this.comboBaudrate.Text=Convert.ToString(item);
                this.comm.PortName = this.comboPortName.Text;
            }
        }

        private void CTextBox1(object item)
        {
            if (this.comboPortName.InvokeRequired)
            {
                // This is a worker thread so delegate the task.
                this.comboPortName.Invoke(new TextBoxDelegate1(this.CTextBox1), item);
            }
            else
            {
                // This is the UI thread so perform the task.
                this.comboPortName.Text = Convert.ToString(item);
                this.comm.PortName = this.comboPortName.Text;
            }
        }

        private void SendBox(object item)
        {
            if (this.comboBaudrate.InvokeRequired)
            {
                // This is a worker thread so delegate the task.
                this.txSend.Invoke(new SendBoxDelegate(this.SendBox), item);
            }
            else
            {
                // This is the UI thread so perform the task.
                this.txSend.Text = Convert.ToString(item);
               // this.comm.PortName = this.comboPortName.Text;
            }
        }

        private string GetBox()
        {
            if (this.txGet.InvokeRequired)
            {
                // This is a worker thread so delegate the task.
                this.txSend.Invoke(new GetBoxDelegate(this.GetBox));
            }
          
                // This is the UI thread so perform the task.
                return Convert.ToString(this.txGet.Text);
                // this.comm.PortName = this.comboPortName.Text;
            
        }
        private void CheckBox()
        {
            if (this.comboBaudrate.InvokeRequired)
            {
                // This is a worker thread so delegate the task.
                this.txSend.Invoke(new CheckBoxDelegate(this.CheckBox));
            }
            else
            {
                // This is the UI thread so perform the task.
                this.checkBoxNewlineSend.Checked = true;
                // this.comm.PortName = this.comboPortName.Text;
            }
        }

        void comm_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            int n = comm.BytesToRead;
            byte[] buf = new byte[n];
            received_count += n;
            comm.Read(buf, 0, n);
            builder.Remove(0, builder.Length);
            this.Invoke((EventHandler)(delegate
            {
                if (checkBoxHexView.Checked)
                {
                    foreach (byte b in buf)
                    {
                        builder.Append(b.ToString("X2") + " ");
                    }
                }
                else
                {
                    builder.Append(Encoding.ASCII.GetString(buf));
                }
                this.txGet.AppendText(builder.ToString());
                //MessageBox.Show(builder.ToString());
                labelGetCount.Text = "Get:" + received_count.ToString();
            }));
        }

        private void buttonOpenClose_Click(object sender, EventArgs e)
        {
            if (comm.IsOpen)
            {
                comm.Close();
            }
            else
            {
                if (button1.Enabled == true)
                {
                    comm.PortName = comboPortName.Text;
                    comm.BaudRate = int.Parse(comboBaudrate.Text);
                }
                    try
                {
                    comm.Open();
                }
                catch (Exception ex)
                {
                    comm = new SerialPort();
                    MessageBox.Show(ex.Message);
                }
            }
            if (button1.Enabled == true)
            {
                buttonOpenClose.Text = comm.IsOpen ? "Close" : "Open";
                buttonSend.Enabled = comm.IsOpen;
            }
        }

        private void checkBoxNewlineGet_CheckedChanged(object sender, EventArgs e)
        {
            txGet.WordWrap = checkBoxNewlineGet.Checked;
        }

        private void buttonSend_Click(object sender, EventArgs e)
        {
            int n = 0;
            if (checkBoxHexSend.Checked)
            {
                MatchCollection mc = Regex.Matches(txSend.Text, @"(?i)[\da-f]{2}");
                List<byte> buf = new List<byte>();
                foreach (Match m in mc)
                {
                    buf.Add(byte.Parse(m.Value));
                }
                comm.Write(buf.ToArray(), 0, buf.Count);
                n = buf.Count;
            }
            else
            {
                if (checkBoxNewlineSend.Checked)
                {
                    comm.WriteLine(txSend.Text);
                    n = txSend.Text.Length + 2;
                }
                else
                {
                    comm.Write(txSend.Text);
                    n = txSend.Text.Length;
                }
            }
            send_count += n;
            if (button1.Enabled == true)
            {
                labelSendCount.Text = "Send:" + send_count.ToString();
            }
        }

        private void buttonReset_Click(object sender, EventArgs e)
        {
            send_count = received_count = 0;
            labelGetCount.Text = "Get:0";
            labelSendCount.Text = "Send:0";
        }

        //////////////////////////////////////////////////////////////////////////////
        ///Start Server
        private void button1_Click(object sender, EventArgs e)
        {
            //We are using TCP sockets
            serverSocket = new Socket(AddressFamily.InterNetwork,
                                      SocketType.Stream,
                                      ProtocolType.Tcp);
            button1.Enabled = false;
            button2.Enabled = true;

            this.buttonOpenClose.Enabled = false;
            this.buttonSend.Enabled = false;

            //Assign the any IP of the machine and listen on port number 8003
            IPEndPoint ipEndPoint = new IPEndPoint(IPAddress.Any, 8003);

            //Bind and listen on the given address
            serverSocket.Bind(ipEndPoint);
            serverSocket.Listen(4);

            //Accept the incoming clients
            serverSocket.BeginAccept(new AsyncCallback(OnAccept), null);
        }

        private void OnAccept(IAsyncResult ar)
        {
            try
            {
                Socket clientSocket = serverSocket.EndAccept(ar);

                //Start listening for more clients
                serverSocket.BeginAccept(new AsyncCallback(OnAccept), null);

                //Once the client connects then start receiving the commands from her
                clientSocket.BeginReceive(byteData, 0, byteData.Length, SocketFlags.None,
                    new AsyncCallback(OnReceive), clientSocket);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "SGSserverTCP",
                    MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void OnReceive(IAsyncResult ar)
        {
            try
            {
                Socket clientSocket = (Socket)ar.AsyncState;
                clientSocket.NoDelay = true;
                clientSocket.EndReceive(ar);
                string strName1 = Encoding.UTF8.GetString(byteData, 0, byteData.Length);
                string[] res = strName1.Split('.');
                string strName = res[0];
                string[] arr = strName.Split(' ');
                
                if (arr.Length == 4)
                {
                    if (arr[0] == "open" || arr[0] == "OPEN" )
                    {
                        if (!comm.IsOpen)
                        {
                            returnMsg = "Port opened";
                            CTextBox(arr[2]);
                            CTextBox1(arr[2]);                            
                            buttonOpenClose_Click(null, null);
                        }
                        else
                        {
                            returnMsg = "Port is already open.";
                        }
                    }
                }
                else if (arr.Length == 8)
                {
                        if (!comm.IsOpen)
                        {
                            returnMsg = "Please open the port";
                        }
                        else
                        {
                            string s;
                            CheckBox();
                            if (arr[0] == "set" || arr[0] == "SET")
                            {
                         
                              /*  s = "s 0xc3 "+arr[3];
                                SendBox(s);
                                buttonSend_Click(null, null);
                                Thread.Sleep(1000);*/

                                // Disable amplifier
                                Thread.Sleep(1000);
                                s = "s r0x24 0";
                                SendBox(s);
                                buttonSend_Click(null, null);

                                s = "s 0xc4 "+arr[3];
                                SendBox(s);
                                buttonSend_Click(null, null);
                                Thread.Sleep(1000);
                                s = " s 0xc6 "+arr[4];
                                SendBox(s);
                                buttonSend_Click(null, null);
                                Thread.Sleep(1000);
                                s = " s 0xc24 "+arr[6];
                                SendBox(s);
                                buttonSend_Click(null, null);
                                Thread.Sleep(1000);
                                s = "t 2";
                                SendBox(s);
                                buttonSend_Click(null, null);
                            
                            }
                            else if (arr[0] == "move" || arr[0] == "MOVE")
                            {
                                if (arr[1] == "f" || arr[1] == "F")
                                {
                                    s = "s r0xca "+arr[3];
                                    SendBox(s);
                                    buttonSend_Click(null, null);
                                }
                                else if(arr[1] == "b" || arr[1] == "B")
                                {
                                    int i = Convert.ToInt32(  arr[3]);
                                    i = i - 2*i;
                                   string t = Convert.ToString(i);
                                    s = "s r0xca "+ t;
                                    SendBox(s);
                                    buttonSend_Click(null, null);
                                }
                                if (arr[2] == "a" || arr[2] == "A")
                                {
                                    s = "s r0xc8 0";
                                    SendBox(s);
                                    buttonSend_Click(null, null);
                                }
                                else if(arr[2] == "r" || arr[2] == "R")
                                {
                                     s = "s r0xc8 256";
                                    SendBox(s);
                                    buttonSend_Click(null, null);
                                }
                                Thread.Sleep(1000);
                                s = "s r0xcb " + arr[4];
                                SendBox(s);
                                buttonSend_Click(null, null);

                                Thread.Sleep(1000);
                                s = "s r0xcc " + arr[5];
                                SendBox(s);
                                buttonSend_Click(null, null);

                                Thread.Sleep(1000);
                                s = "s r0xcd " + arr[6];
                                SendBox(s);
                                buttonSend_Click(null, null);

                                Thread.Sleep(1000);
                                s= "s r0x24 21";
                               SendBox(s);
                               buttonSend_Click(null, null);

                               Thread.Sleep(1000);
                                s= "g r0x32";
                                SendBox(s);
                                buttonSend_Click(null, null);

                                Thread.Sleep(1000);
                                s = "t 1";
                                SendBox(s);
                                buttonSend_Click(null, null);


                            }
                           // SendBox(s);
                           // buttonSend_Click(null, null);
                            returnMsg = GetBox();
                        }
                    }

                
                else
                {
                    returnMsg = "Command syntax error";
                    byte[] message = Encoding.UTF8.GetBytes(returnMsg);
                    clientSocket.BeginSend(message, 0, message.Length, SocketFlags.None, new AsyncCallback(OnSend), clientSocket);
                }

                if (arr[arr.Length-1] == "?")
                {
                    byte[] message = Encoding.UTF8.GetBytes(returnMsg);

                    clientSocket.BeginSend(message, 0, message.Length, SocketFlags.None, new AsyncCallback(OnSend), clientSocket);
                }

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "SGSserverTCP", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        public void OnSend(IAsyncResult ar)
        {
            try
            {
                Socket client = (Socket)ar.AsyncState;
                client.EndSend(ar);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "SGSserverTCP", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

 
        public IList<ArraySegment<byte>> buffer { get; set; }

        private void button2_Click_1(object sender, EventArgs e)
        {
            this.button1.Enabled = true;
            this.button2.Enabled = false;
            this.buttonOpenClose.Enabled = true;
            this.buttonSend.Enabled = true;
            MessageBox.Show("Please reboot server to allow client access again.");
            //serverSocket.Close();
            // tcpServerListener.Stop();
        }
    }
}
