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

	

	private: System::Windows::Forms::TextBox^  textBox1;
	protected: 
	private: System::Windows::Forms::ErrorProvider^  errorProvider1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;


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
			// treeView1
			// 
			this->treeView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->treeView1->Location = System::Drawing::Point(12, 142);
			this->treeView1->Name = L"treeView1";
			this->treeView1->Size = System::Drawing::Size(317, 97);
			this->treeView1->TabIndex = 6;
			this->treeView1->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &Form1::treeView1_AfterSelect);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(341, 251);
			this->Controls->Add(this->treeView1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Name = L"Form1";
			this->Text = L"Simulador de Push-Down Automata";
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
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void treeView1_AfterSelect(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e) {
		 }
		 String^ imprimirPila(stack<char> pila){
			 String^ contPila;
			 stack<char> m_pila = pila; 
			 while(m_pila.size()>0){
				 contPila= contPila +  (m_pila.top()-48).ToString();
				 m_pila.pop();
			 }
			 return "{"+contPila+"}";
		 }

		 bool ValidarPalabraBinaria(String^ palabra){
			 for(int i = 0; i< palabra->Length; i++){
				 if(palabra[i] !='0' && palabra[i] !='1') return false;
			 }
			 return true;
		 }

		 TreeNode^ GenerarNodo(String^ palabra, int estado, stack<char> pila){
			 String^ estado_s = (estado==Q0)?"Q0":"Q1";
			 String^ instantanea = "( " + palabra + " | " + estado_s + " | " + imprimirPila(pila) + " )";
			 return gcnew TreeNode(instantanea);
		 }

		 TreeNode^ GenerarArbol(String^ palabra, int estado, stack<char> pila){
			 TreeNode^ raiz = GenerarNodo(palabra,estado,pila);
			 TreeNode^ izquierda;
			 TreeNode^ derecha;
			 try{
				 if(estado == Q0){
					 if(palabra->IsNullOrEmpty(palabra) && pila.empty()){
						 raiz->Text = raiz->Text + " - ACEPTADA";
					 }
					 else if(!palabra->IsNullOrEmpty(palabra)){
						 pila.push(palabra[0]);
						 izquierda = GenerarArbol(palabra->Substring(1,palabra->Length-1),Q0,pila);
						 derecha = GenerarArbol(palabra->Substring(1,palabra->Length-1),Q1,pila);
						 raiz->Nodes->Add(izquierda);
						 raiz->Nodes->Add(derecha);
					 }else{
						 raiz->Text = raiz->Text + " - RECHAZADA";
					 }
				 }else if(estado == Q1){
					 if(palabra->IsNullOrEmpty(palabra) && pila.empty()){
						 raiz->Text = raiz->Text + " - ACEPTADA";
					 }
					 else if(!palabra->IsNullOrEmpty(palabra) && !pila.empty() && palabra[0] == pila.top()){
						 pila.pop();
						 derecha = GenerarArbol(palabra->Substring(1,palabra->Length-1),Q1,pila);
						 raiz->Nodes->Add(derecha);
					 }
					 else raiz->Text = raiz->Text + " - RECHAZADA";
				 }
				 return raiz;
			 }catch(exception e){
				 MessageBox::Show("!: ERROR");
			 }

		 }

		 void ProcesarCadena(TreeView^ arbol, String^ cadena,int estado,stack<char> pila){
			 arbol->Nodes->Add(GenerarArbol(cadena,estado,pila));
		 }

		 

private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 
		 }
			private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

						 treeView1->Nodes->Clear();
						 String^ palabra = textBox1->Text;
						 stack<char> *pila = new stack<char>();
						 int estado = Q0;

						 ProcesarCadena(treeView1,palabra,Q0,(*pila));

						 treeView1->ExpandAll();
					 }

 
};
	
	
}

