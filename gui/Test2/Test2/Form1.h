#pragma once


namespace Test2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 

	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::Button^  run;
	private: System::Windows::Forms::Button^  browse;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::TextBox^  outputBox;
	private: System::Windows::Forms::TextBox^  codeBox;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::ComponentModel::IContainer^  components;

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->codeBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->outputBox = (gcnew System::Windows::Forms::TextBox());
			this->run = (gcnew System::Windows::Forms::Button());
			this->browse = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->SuspendLayout();
			// 
			// splitContainer1
			// 
			this->splitContainer1->Location = System::Drawing::Point(12, 66);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->label2);
			this->splitContainer1->Panel1->Controls->Add(this->codeBox);
			this->splitContainer1->Panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::splitContainer1_Panel1_Paint);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->BackColor = System::Drawing::SystemColors::Control;
			this->splitContainer1->Panel2->Controls->Add(this->label1);
			this->splitContainer1->Panel2->Controls->Add(this->outputBox);
			this->splitContainer1->Panel2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->splitContainer1->Panel2->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->splitContainer1->Size = System::Drawing::Size(1050, 575);
			this->splitContainer1->SplitterDistance = 571;
			this->splitContainer1->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(186, 6);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(117, 23);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Source Code";
			// 
			// codeBox
			// 
			this->codeBox->BackColor = System::Drawing::SystemColors::Window;
			this->codeBox->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->codeBox->Location = System::Drawing::Point(3, 34);
			this->codeBox->Multiline = true;
			this->codeBox->Name = L"codeBox";
			this->codeBox->ReadOnly = true;
			this->codeBox->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->codeBox->Size = System::Drawing::Size(565, 538);
			this->codeBox->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(173, 6);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(93, 23);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Error Log";
			// 
			// outputBox
			// 
			this->outputBox->BackColor = System::Drawing::SystemColors::WindowText;
			this->outputBox->ForeColor = System::Drawing::SystemColors::Control;
			this->outputBox->Location = System::Drawing::Point(3, 34);
			this->outputBox->Multiline = true;
			this->outputBox->Name = L"outputBox";
			this->outputBox->ReadOnly = true;
			this->outputBox->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->outputBox->Size = System::Drawing::Size(469, 538);
			this->outputBox->TabIndex = 0;
			// 
			// run
			// 
			this->run->Enabled = false;
			this->run->Location = System::Drawing::Point(112, 12);
			this->run->Name = L"run";
			this->run->Size = System::Drawing::Size(79, 35);
			this->run->TabIndex = 5;
			this->run->Text = L"Run";
			this->run->UseVisualStyleBackColor = true;
			this->run->Click += gcnew System::EventHandler(this, &Form1::run_Click);
			// 
			// browse
			// 
			this->browse->Location = System::Drawing::Point(12, 12);
			this->browse->Name = L"browse";
			this->browse->Size = System::Drawing::Size(79, 35);
			this->browse->TabIndex = 7;
			this->browse->Text = L"Browse";
			this->browse->UseVisualStyleBackColor = true;
			this->browse->Click += gcnew System::EventHandler(this, &Form1::browse_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(9, 50);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(1054, 13);
			this->label3->TabIndex = 11;
			this->label3->Text = resources->GetString(L"label3.Text");
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1076, 662);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->browse);
			this->Controls->Add(this->run);
			this->Controls->Add(this->splitContainer1);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"SYNTAX CHECKER";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel1->PerformLayout();
			this->splitContainer1->Panel2->ResumeLayout(false);
			this->splitContainer1->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void splitContainer1_Panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }



private: System::Void run_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->outputBox->Text = "syntax checker";
			 
			 this->run->Enabled = false;
		 }

private: System::Void browse_Click(System::Object^  sender, System::EventArgs^  e) {	

			 if(openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
      {
         System::IO::StreamReader ^ sr = gcnew
            System::IO::StreamReader(openFileDialog1->FileName);
		this->codeBox->Text = sr->ReadToEnd();
		 //String^ lines = gcnew String(sr->ReadToEnd());
		 
         sr->Close();
      }
		this->run->Enabled = true;
		 }



private: System::Void label_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }

private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void codeBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }

private: System::Void outputBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}