#include <Windows.h>
#include <windows.h> 
#include <wininet.h> 
#include <iostream>
#pragma once
#pragma comment(lib, "wininet")


namespace TCPSocketClient {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Net;
	using namespace System::Net::Sockets;
	using namespace System::Text;
	using namespace System::Diagnostics;
	using namespace System::ComponentModel;
	using namespace System::Windows;
	

	/// <summary>02
	/// Summary for FormTCPSocketClient
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class FormTCPSocketClient : public System::Windows::Forms::Form
	{
	public:
		FormTCPSocketClient(void)
		{
			InitializeComponent();
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormTCPSocketClient()
		{
			if (components)
			{
				delete components;
			}
		}
	private: static const int PORT = 3390;
	private: static const int MAX_BUF_SIZE = 255;
	private: static const int RCV_TIME_OUT = 100000; // in milliseconds
	private: static const char QUESTION_MARK = '.';
    private: static const char EXCLAIMATION_MARK = '!';
	private: static String^ ip = "";
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  TextBoxIpAddress;


	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  TextBoxScpiCmd;
	private: System::Windows::Forms::Button^  ButtonRun;





	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  TextBoxResponse;


	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  TextBoxStatus;

	private: System::Windows::Forms::Button^  ButtonQuit;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button3;




	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->TextBoxIpAddress = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->TextBoxScpiCmd = (gcnew System::Windows::Forms::TextBox());
			this->ButtonRun = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->TextBoxResponse = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->TextBoxStatus = (gcnew System::Windows::Forms::TextBox());
			this->ButtonQuit = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Verdana", 12.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(117, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(202, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"TCP Socket Program";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(98, 57);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(247, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"For the cloud manufacturing project";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(53, 84);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 16);
			this->label3->TabIndex = 2;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(53, 111);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 16);
			this->label4->TabIndex = 3;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(59, 73);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(319, 16);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Enter the IP Address and a command or query.";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(118, 89);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(187, 16);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Then click the RUN button.";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(139, 126);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(166, 16);
			this->label7->TabIndex = 6;
			this->label7->Text = L"IP Address or Hostname";
			// 
			// TextBoxIpAddress
			// 
			this->TextBoxIpAddress->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TextBoxIpAddress->Location = System::Drawing::Point(107, 156);
			this->TextBoxIpAddress->Name = L"TextBoxIpAddress";
			this->TextBoxIpAddress->Size = System::Drawing::Size(238, 27);
			this->TextBoxIpAddress->TabIndex = 0;
			this->TextBoxIpAddress->Text = L"129.105.90.68";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(122, 197);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(197, 16);
			this->label8->TabIndex = 8;
			this->label8->Text = L"Enter the command or query";
			// 
			// TextBoxScpiCmd
			// 
			this->TextBoxScpiCmd->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TextBoxScpiCmd->Location = System::Drawing::Point(84, 230);
			this->TextBoxScpiCmd->Name = L"TextBoxScpiCmd";
			this->TextBoxScpiCmd->Size = System::Drawing::Size(294, 27);
			this->TextBoxScpiCmd->TabIndex = 1;
			this->TextBoxScpiCmd->Text = L"open\?";
			// 
			// ButtonRun
			// 
			this->ButtonRun->Location = System::Drawing::Point(166, 266);
			this->ButtonRun->Name = L"ButtonRun";
			this->ButtonRun->Size = System::Drawing::Size(110, 30);
			this->ButtonRun->TabIndex = 2;
			this->ButtonRun->Text = L"RUN";
			this->ButtonRun->UseVisualStyleBackColor = true;
			this->ButtonRun->Click += gcnew System::EventHandler(this, &FormTCPSocketClient::ButtonRun_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(155, 354);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(114, 16);
			this->label9->TabIndex = 11;
			this->label9->Text = L"Query Response";
			// 
			// TextBoxResponse
			// 
			this->TextBoxResponse->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TextBoxResponse->Location = System::Drawing::Point(83, 390);
			this->TextBoxResponse->Multiline = true;
			this->TextBoxResponse->Name = L"TextBoxResponse";
			this->TextBoxResponse->ReadOnly = true;
			this->TextBoxResponse->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->TextBoxResponse->Size = System::Drawing::Size(284, 64);
			this->TextBoxResponse->TabIndex = 3;
			this->TextBoxResponse->Text = L"none";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(186, 470);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(52, 16);
			this->label10->TabIndex = 13;
			this->label10->Text = L"Status";
			this->label10->Click += gcnew System::EventHandler(this, &FormTCPSocketClient::label10_Click);
			// 
			// TextBoxStatus
			// 
			this->TextBoxStatus->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TextBoxStatus->Location = System::Drawing::Point(83, 489);
			this->TextBoxStatus->Multiline = true;
			this->TextBoxStatus->Name = L"TextBoxStatus";
			this->TextBoxStatus->ReadOnly = true;
			this->TextBoxStatus->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->TextBoxStatus->Size = System::Drawing::Size(284, 97);
			this->TextBoxStatus->TabIndex = 4;
			this->TextBoxStatus->Text = L"none";
			// 
			// ButtonQuit
			// 
			this->ButtonQuit->Location = System::Drawing::Point(159, 592);
			this->ButtonQuit->Name = L"ButtonQuit";
			this->ButtonQuit->Size = System::Drawing::Size(110, 30);
			this->ButtonQuit->TabIndex = 5;
			this->ButtonQuit->Text = L"QUIT";
			this->ButtonQuit->UseVisualStyleBackColor = true;
			this->ButtonQuit->Click += gcnew System::EventHandler(this, &FormTCPSocketClient::QUIT_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(30, 312);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(110, 30);
			this->button2->TabIndex = 15;
			this->button2->Text = L"CAMERA";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &FormTCPSocketClient::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(293, 313);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(110, 30);
			this->button1->TabIndex = 16;
			this->button1->Text = L"DATA";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &FormTCPSocketClient::button1_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(158, 312);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(111, 31);
			this->button3->TabIndex = 17;
			this->button3->Text = L"TEST";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &FormTCPSocketClient::button3_Click);
			// 
			// FormTCPSocketClient
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(444, 663);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->ButtonQuit);
			this->Controls->Add(this->TextBoxStatus);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->TextBoxResponse);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->ButtonRun);
			this->Controls->Add(this->TextBoxScpiCmd);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->TextBoxIpAddress);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->Name = L"FormTCPSocketClient";
			this->Text = L"TCPSocketClient";
			this->Load += gcnew System::EventHandler(this, &FormTCPSocketClient::FormTCPSocketClient_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
/************************* FUNCTION HEADER ***********************************
 *	Function      : QUIT_Click
 *	Description   : This method is called when QUIT button clicked.
 *	Procedure     :	terminates form by calling Close(). 
 *	Return Value  : void
 *	Called by     : 
 *	Remarks       : 
 *
 ****************************************************************************/
private: System::Void QUIT_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 Close();
		 }
/************************* FUNCTION HEADER ************************************
 *	Function      : ButtonRun_Click
 *	Description   : This method is called when RUN button clicked.
 *	Procedure     : create socket,estabish connection with server,send SCPI  
 *					command and receive the response.
 *	Return Value  : void
 *	Called by     : 
 *	Remarks       : 
 *
 *****************************************************************************/
private: System::Void ButtonRun_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 int nLength = 0;
			 Socket^ socket = nullptr;
			 String^ userData;
			 LARGE_INTEGER start;
			 LARGE_INTEGER end;
			 LARGE_INTEGER freq;
			 __int64 diff(0);
			 double duration(0);
			 

			 try
			 {
				 TextBoxResponse->Text = "none";
				 TextBoxResponse->Update();
				 if(TextBoxIpAddress->Text == "")
				 {
					 TextBoxStatus->Text = "IP field is empty";
					 TextBoxStatus->Update();
					 return;
				 }
				 if(TextBoxScpiCmd->Text == "")
				 {
					 TextBoxStatus->Text = "SCPI command field is empty";
					 TextBoxStatus->Update();
					 return;
				 }
				 TextBoxStatus->Text = "Running";
				 TextBoxStatus->Update();

				 //Creating the socket
				 socket = gcnew Socket(AddressFamily::InterNetwork,
												SocketType::Stream,
												ProtocolType::Tcp);
				 socket->Blocking = true;
				 socket->ReceiveTimeout = RCV_TIME_OUT;
				 //Connecting 
				 socket->Connect(TextBoxIpAddress->Text,PORT); 
				 array<Byte>^ bySendBuffer = Encoding::ASCII->GetBytes(TextBoxScpiCmd->Text);
				 array<Byte>^ byRecvBuffer = gcnew array<Byte>(MAX_BUF_SIZE);
				 //Sending the command
				 socket->Send(bySendBuffer,bySendBuffer->Length,SocketFlags::None);

				 //Retrieves the frequency of the high-resolution performance counter
				 QueryPerformanceFrequency(&freq);
				 //Retrieves the current value of the high-resolution performance counter
				 QueryPerformanceCounter( &start);
				 //Check if it is open command

				 nLength = TextBoxScpiCmd->TextLength;

				 bool openTrue = false;
				 if (nLength == 17)
					 openTrue = true;
				
				  
				 // check command contains '?' character
				 if(QUESTION_MARK == bySendBuffer[nLength-1])
				 {
					//Receiving the response
					socket->Receive(byRecvBuffer, MAX_BUF_SIZE, SocketFlags::None);
					//clock time
					QueryPerformanceCounter( &end ); 
					//calculate duration
					duration= (double)(freq.QuadPart);
					diff = end.QuadPart-start.QuadPart;
					duration = diff/duration;
					if (!openTrue)
						duration = duration - 0.105;


					TextBoxResponse->Text = Encoding::ASCII->GetString(byRecvBuffer);
					TextBoxResponse->Update();

					//send delay and ip back to server
					if (ip=="")
						ip = this->getExternalIP();
					userData= ((double) duration).ToString();
					userData= ip + " " + userData;
					Run_run(userData);

				 }
				 //Closing the socket
				 if(EXCLAIMATION_MARK == bySendBuffer[nLength-1])
				 {
				 socket->Close();
				 }
				 TextBoxStatus->Text = "Success";

				 //TextBoxStatus->Text =  ( ( (IPEndPoint^)(socket->LocalEndPoint) )->Address)->ToString();
				 TextBoxStatus->Update();
			 }
			 catch(Exception^ Ex)
			 {
				 TextBoxResponse->Text = "none";
				 TextBoxResponse->Update();
				 TextBoxStatus->Text = Ex->Message;
				 TextBoxStatus->Update();
				 if(socket != nullptr)
				 {
					 //Closing the socket
					 socket->Close();
				 }
			 }
		 }
private: System::Void Run_run(System::String^ userData)
		 {
				 Socket^ socket = nullptr;
				 //Creating the socket
				 socket = gcnew Socket(AddressFamily::InterNetwork,
												SocketType::Stream,
												ProtocolType::Tcp);
				 socket->Blocking = true;
				 socket->ReceiveTimeout = RCV_TIME_OUT;
				 //Connecting 
				 socket->Connect(TextBoxIpAddress->Text,PORT); 
				 array<Byte>^ userInfo = Encoding::ASCII->GetBytes(userData);
				 //Sending info
				 socket->Send(userInfo,userInfo->Length,SocketFlags::None);		  
		 }
private: System::Void FormTCPSocketClient_Load(System::Object^  sender, System::EventArgs^  e) {


		 }
private: System::Void label11_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			// Process* myProcess = new Process();
			// HINSTANCE hInstance = ShellExecute(NULL, "open", "129.105.90.32", NULL, NULL, SW_SHOW);
			 Process::Start( "chrome.exe", "129.105.90.32" );
			 
		 }

private: System::Void label10_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
       //HINSTANCE hInstance = ShellExecute(NULL, "open", "C:\Users\sooding\Desktop\SocketSniff.exe", NULL, NULL, SW_SHOW);
       //HINSTANCE hInstance = ShellExecute(NULL, "open", "C:\Users\sooding\Desktop\SocketSniff.exe", NULL, NULL, SW_SHOW);
		 Process::Start( "chrome.exe", "https://www.dropbox.com/sh/q9i8yl4z3e66dsj/cRBGL_bIQw");
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {

		  Process::Start( "chrome.exe", "http://129.105.90.68/data.html" );
			 
		 }

 
 
private: System::String^ getExternalIP()
{
    HINTERNET hInternet, hFile;
    DWORD rSize;
    char buffer[47];
	try {
		hInternet = InternetOpen(NULL, INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
		hFile = InternetOpenUrlA(hInternet, "http://automation.whatismyip.com/n09230945.asp", NULL, 0, INTERNET_FLAG_RELOAD, 0);
		InternetReadFile(hFile, &buffer, sizeof(buffer), &rSize);
		buffer[rSize] = '\0';

		InternetCloseHandle(hFile);
		InternetCloseHandle(hInternet);
		String^ returnIP = gcnew String(buffer);
		return returnIP;
	} catch (Exception^ ex) {
		return "";
	}

}

};
}