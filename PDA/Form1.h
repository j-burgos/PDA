#pragma once
#include <stack>
#include <iostream>
#include <string>

#define Q0 0
#define Q1 1
#define Q2 2 
namespace PDA {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Resumen de Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private: bool ValidarPalabraBinaria(String^ palabra);
			 void ProcesarCadena(String^ palabra,int estado,stack<char> pila);
			 String^ imprimirPila(stack<char> pila);

	private: System::Windows::Forms::TextBox^  textBox1;
	protected: 
	private: System::Windows::Forms::ErrorProvider^  errorProvider1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TreeView^  treeView1;

	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->errorProvider1 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->treeView1 = (gcnew System::Windows::Forms::TreeView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->errorProvider1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(75, 20);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(232, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// errorProvider1
			// 
			this->errorProvider1->BlinkStyle = System::Windows::Forms::ErrorBlinkStyle::NeverBlink;
			this->errorProvider1->ContainerControl = this;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(22, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(47, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Cadena:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(173, 65);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Cancelar";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(254, 65);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Procesar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(36, 100);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 5;
			// 
			// treeView1
			// 
			this->treeView1->Location = System::Drawing::Point(75, 142);
			this->treeView1->Name = L"treeView1";
			this->treeView1->Size = System::Drawing::Size(205, 97);
			this->treeView1->TabIndex = 6;
			this->treeView1->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &Form1::treeView1_AfterSelect);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(341, 251);
			this->Controls->Add(this->treeView1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->errorProvider1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				 if(ValidarPalabraBinaria(textBox1->Text)){
					 errorProvider1->Clear();
					 button2->Enabled = true;
				 }else{
					 errorProvider1->SetError(textBox1,"La palabra contiene símbolos no válidos");
					 button2->Enabled = false;
				 }
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 textBox3->Text = "";
				treeView1->Nodes->Clear();
				 String^ palabra = textBox1->Text;
				stack<char> *pila = new stack<char>();
				
				 ProcesarCadena(palabra,Q0,(*pila));

			//	MessageBox(0, palabra, "Demostracion simple", 0);
			
			 }
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void treeView1_AfterSelect(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e) {
		 }
};
	bool Form1::ValidarPalabraBinaria(String^ palabra){
			 for(int i = 0; i< palabra->Length; i++){
				 if(palabra[i] !='0' && palabra[i] !='1') return false;
			 }
			 return true;
		 };

	void Form1::ProcesarCadena(String^ cadena,int estado,stack<char> pila){	
		if(estado == Q0 ){
		treeView1->Nodes->Add("( q0 ," + cadena +"," +imprimirPila(pila) +"Z0"+ ")" );
		}else {
		treeView1->Nodes->Add("(q1 ," + cadena +"," +imprimirPila(pila) + "Z0" + ")" );
		
		}
		try{
			if(estado == Q0){
				if(!(String::IsNullOrEmpty(cadena))){		
				pila.push(cadena[0]);
				ProcesarCadena(cadena->Substring(1,cadena->Length-1),Q0,pila);
				ProcesarCadena(cadena->Substring(1,cadena->Length-1),Q1,pila);	
				}else {
					
				}
			}else if(estado == Q1){
				if((String::IsNullOrEmpty(cadena)) && pila.size()<=1){
					textBox3->Text = "Aceptada";
					return;
				} 
					if(!(String::IsNullOrEmpty(cadena)) && !(pila.empty()) && pila.top() == cadena[0]){
					pila.pop();	
					ProcesarCadena(cadena->Substring(1,cadena->Length-1),Q1,pila);
					}
					
				}else{
					
				

			}
			}catch(exception e){
		
		}
	}



	String^ Form1::imprimirPila(stack<char> pila){
		String^ contPila;
		stack<char> m_pila = pila; 
		while(m_pila.size()>0){
			contPila= contPila +  (m_pila.top()-48).ToString();
			
			m_pila.pop();
		}
		return contPila;
	
	
	}
}

