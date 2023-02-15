#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Definimos las interfaces
class ArtistaNacional{
public:
    virtual string getAcento() = 0;
};

class Pago
{

public:
    virtual bool ComprarBoleta() = 0;
};

class MetodoPago
{
public:
    virtual bool Tarjeta() = 0;
    virtual bool Efectivo() = 0;
    virtual bool Nequi() = 0;
};

class MetodoBoletos
{

public:
    virtual void AgregarBoleta() = 0;
    virtual void RestarBoleta() = 0;
};

class Login
{
public:
    virtual bool login() = 0;
};

class Publicidad
{
public:
    virtual bool publicidad() = 0;
};

class Efectos
{

public:
    virtual bool ShowFuego() = 0;
    virtual bool ShowLuces() = 0;
};

class Movilizacion
{

public:
    virtual string TipoVehiculo() = 0;
};
// Cerramos Interfaces

// Definimos las clases Abstractas
class Persona
{
protected:
    int id;
    string nombre;
    int edad;

public:
    Persona()
    {
        id = 0;
        nombre = "";
        edad = 0;
    }
    Persona(int id, string nombre, int edad) : id(id), nombre(nombre), edad(edad)
    {
    }
    // Definimos el metodo virtualmente puro
    virtual int Salario() = 0;
    virtual int getTipo()=0;
    // Hacemos la encapsulacion
    int getId()
    {
        return id;
    }

    void setId(int id)
    {
        this->id = id;
    }
    string getnombre()
    {
        return nombre;
    }

    void setNombre(string nombre)
    {
        this->nombre = nombre;
    }

    int getEdad()
    {
        return edad;
    }

    void setEdad(int edad)
    {
        this->edad = edad;
    }
    virtual void print()
    {
        cout << "Id: " << getId() << endl;
        cout << "Nombre: " << getnombre() << endl;
        cout << "Edad: " << getEdad() << endl;
    }
    friend ostream &operator<<(ostream &output, Persona &p)
    {
        output << endl
               << "Id: " << p.getId() << endl;
        output << endl
               << "Nombre: " << p.getnombre() << endl;
        output << "Edad: " << p.getEdad() << endl;
        // p->print(out);
        return output;
    }
};

class Artista : public Persona
{
protected:
    int AñosExperiencia;
    string apodo;

public:
    Artista() : Persona()
    {
        AñosExperiencia = 0;
        apodo = "";
    }
    Artista(int id, string nombre, int edad, int AñosExperiencia, string apodo) : Persona(id, nombre, edad), AñosExperiencia(AñosExperiencia), apodo(apodo)
    {
    }
    int getTipo() override{
        return 1;
    }
    int getAñosExperiencia()
    {
        return AñosExperiencia;
    }

    void setAñosExperiencia(int AñosExperiencia)
    {
        this->AñosExperiencia = AñosExperiencia;
    }

    string getApodo()
    {
        return apodo;
    }

    void setApodo(string apodo)
    {
        this->apodo = apodo;
    }

    int Salario() override
    {
        return 0;
    }
    void print() override
    {
        Persona::print();
        cout << "Años Experiencia " << getAñosExperiencia() << endl;
        cout << "Apodo: " << getApodo() << endl;
    }
    friend ostream &operator<<(ostream &output, Artista &p)
    {
        p.Persona::print();
        output << "Años Experiencia " << p.getAñosExperiencia() << endl;
        output << "Apodo: " << p.getApodo() << endl;
        return output;
    }
    virtual string Presentarse() = 0;
};

class Empleado : public Persona, public Login
{
protected:
    int idTrabajador;
    string Usuario;
    string Contraseña;

public:
    Empleado() : Persona()
    {
        idTrabajador = 0;
        Usuario = "";
        Contraseña = "";
    }
    Empleado(int id, string nombre, int edad, int idTrabajador, string Usuario, string Contraseña) : Persona(id, nombre, edad), idTrabajador(idTrabajador), Usuario(Usuario), Contraseña(Contraseña)
    {
    }

    int getTipo() override{
        return 2;
    }

    int getidTrabajador()
    {
        return idTrabajador;
    }

    void setidTrabajador(int idTrabajador)
    {
        this->idTrabajador = idTrabajador;
    }

    string getUsuario()
    {
        return Usuario;
    }

    void setUsuario(string Usuario)
    {
        this->Usuario = Usuario;
    }

    string getContraseña()
    {
        return Contraseña;
    }

    void setContraseña(string Contraseña)
    {
        this->Contraseña = Contraseña;
    }

    int Salario() override
    {
        return 0;
    }
    void print()
    {
        Persona::print();
        cout << "id Trabajador: " << getidTrabajador() << endl;
        cout << "Usuario:  " << getUsuario() << endl;
        cout << "Contraseña: " << getContraseña() << endl;
    }
    friend ostream &operator<<(ostream &output, Empleado &p)
    {
        p.Persona::print();
        output << "id Trabajador:  " << p.getidTrabajador() << endl;
        output << "Usuario: " << p.getUsuario() << endl;
        output << "Contraseña: " << p.getContraseña() << endl;

        return output;
    }

    virtual string turno() = 0;

    bool login() override
    {
        return true;
    }

    virtual string getTipoContrato() = 0;
};

class Lugar
{
protected:
    string NombreLugar;
    double CapacidadMinima;
    double CapacidadMaxima;

public:
    Lugar()
    {
        NombreLugar = "";
        CapacidadMinima = 0;
        CapacidadMaxima = 0;
    }
    Lugar(string NombreLugar, double CapacidadMinima, double CapacidadMaxima) : NombreLugar(NombreLugar), CapacidadMinima(CapacidadMinima), CapacidadMaxima(CapacidadMaxima)
    {
    }
    // Definimos el metodo virtualmente puro
    virtual string Example() = 0;

    // Hacemos la encapsulacion
    string getNombreLugar()
    {
        return NombreLugar;
    }

    void setNombreLugar(int NombreLugar)
    {
        this->NombreLugar = NombreLugar;
    }
    double getCapacidadMinima()
    {
        return CapacidadMinima;
    }

    void setCapacidadMinima(double CapacidadMinima)
    {
        this->CapacidadMinima = CapacidadMinima;
    }

    double getCapacidadMaxima()
    {
        return CapacidadMaxima;
    }

    void setCapacidadMaxima(double CapacidadMaxima)
    {
        this->CapacidadMaxima = CapacidadMaxima;
    }
    void print()
    {
        cout << "Nombre del Lugar: " << getNombreLugar() << endl;
        cout << "Capacidad Minima de personas: " << getCapacidadMinima() << endl;
        cout << "Capacidad Maxima de personas: " << getCapacidadMaxima() << endl;
    }
    friend ostream &operator<<(ostream &output, Lugar &p)
    {
        output << endl
               << "Nombre del Lugar: " << p.getNombreLugar();
        output << endl
               << "Capacidad Minima de personas: " << p.getCapacidadMinima() << endl;
        output << "Capacidad Maxima de personas: " << p.getCapacidadMaxima() << endl;

        return output;
    }
};

class Ubicacion
{
protected:
    string Direccion;
    string ciudad;

public:
    Ubicacion()
    {
        Direccion = "";
        ciudad = "";
    }
    Ubicacion(string Direccion, string ciudad) : Direccion(Direccion), ciudad(ciudad)
    {
    }
    // Definimos el metodo virtualmente puro
    virtual string gps() = 0;

    // Hacemos la encapsulacion
    string getDireccion()
    {
        return Direccion;
    }

    void setDireccion(string Direccion)
    {
        this->Direccion = Direccion;
    }
    string getciudad()
    {
        return ciudad;
    }

    void setciudad(string ciudad)
    {
        this->ciudad = ciudad;
    }

    void print()
    {
        cout << "Direccion del lugar: " << getDireccion() << endl;
        cout << "Ciudad: " << getciudad() << endl;
    }
    friend ostream &operator<<(ostream &output, Ubicacion &p)
    {
        output << endl
               << "Direccion del lugar: " << p.getDireccion();
        output << endl
               << "Ciudad: " << p.getciudad() << endl;

        return output;
    }
};

class Fecha{
protected:
    string dia, mes ,anio;
public:
    Fecha():dia(""), mes(""), anio(""){}
    Fecha(string dia, string mes, string año): dia(dia), mes(mes), anio(año){}

    const string &getDia() const {
        return dia;
    }

    void setDia(const string &dia) {
        Fecha::dia = dia;
    }

    const string &getMes() const {
        return mes;
    }

    void setMes(const string &mes) {
        Fecha::mes = mes;
    }

    const string &getAnio() const {
        return anio;
    }

    void setAnio(const string &anio) {
        Fecha::anio = anio;
    }
    void print(){
        cout << dia << "/" << mes << "/" << anio;
    }
    friend ostream& operator<< (ostream& out, Fecha fecha){
        out << fecha.dia << "/" << fecha.mes << "/" << fecha.anio << endl;
        return out;
    }
};

class Boletos
{
protected:
    int idBoleto;
    Fecha fechaValidez;

public:
    Boletos(){

        idBoleto = 0;
        fechaValidez = Fecha();
    }
    Boletos(int idBoleto, string dia, string mes, string anio) : idBoleto(idBoleto), fechaValidez(Fecha(dia, mes, anio)){}
    // Definimos el metodo virtualmente puro
    virtual string Manilla() = 0;

    virtual int getTipoBoleto() = 0;

    // Hacemos la encapsulacion
    int getidBoleto()
    {
        return idBoleto;
    }

    void setidBoleto(int idBoleto)
    {
        this->idBoleto = idBoleto;
    }
    Fecha getFechaValidez()
    {
        return fechaValidez;
    }

    void setFechaValidez(Fecha FechaValidez)
    {
        this->fechaValidez = FechaValidez;
    }

    void print()
    {
        cout << "Id del boleto: " << getidBoleto() << endl;
        cout << "Fecha de Validez: " << getFechaValidez() << endl;
    }
    friend ostream &operator<<(ostream &output, Boletos &p)
    {
        output << endl
               << "Id del boleto: " << p.getidBoleto();
        output << endl
               << "Fecha de Validez: " << p.getFechaValidez() << endl;

        return output;
    }
};

class Distribuidora
{
protected:
    string Marca;

public:
    Distribuidora()
    {

        Marca = "";
    }
    Distribuidora(string Marca) : Marca(Marca)
    {
    }
    // Definimos el metodo virtualmente puro
    virtual string getFrase() = 0;

    // Hacemos la encapsulacion

    string getMarca()
    {
        return Marca;
    }

    void setMarca(string Marca)
    {
        this->Marca = Marca;
    }

    void print()
    {
        cout << "Nombre de la marca: " << getMarca() << endl;
    }
    friend ostream &operator<<(ostream &output, Distribuidora &p)
    {
        output << endl
               << "Nombre de la marca: " << p.getMarca();

        return output;
    }
};

// Cierre de clases Abstractas
// Inicio de Clases Concretas

class Manager : public Persona
{

public:
    
    Manager() : Persona(){
    }
    Manager(int id, string nombre, int edad): Persona(id, nombre, edad)
    {

    }
    int Salario() override {

        return 0 ;
    }
    int getTipo() override{

        return 0;
    }
    void representar(){
        cout << "Representar es mi pasion, te sere de ayuda en tu camino como estrella"<<endl;
    }

};

class Cantante : public Artista
{
protected:
    string genero;

public:
    Cantante() : Artista()
    {
        genero = "";
    }
    Cantante(int id, string nombre, int edad, string genero, int AñosExperiencia, string apodo) : Artista(id, nombre, edad, AñosExperiencia, apodo), genero(genero)
    {
    }
    int getTipo() override{
        return 3;
    }
    string getgenero()
    {
        return genero;
    }

    void setgenero(string genero)
    {
        this->genero = genero;
    }

    void print()
    {
    }
    friend ostream &operator<<(ostream &output, Cantante &p)
    {
        p.Artista::print();
        output << "genero musical " << p.getgenero() << endl;
        return output;
    }
    int Salario() override
    {
        return 0;
    }

    string Presentarse() override
    {
        return 0;
    }
};
class Dj : public Artista, public ArtistaNacional
{
protected:
    string marcaMezclador;
    string ciudad;

public:
    Dj() : Artista()
    {
        marcaMezclador = "";
        ciudad = "";
    }
    int getTipo() override{
        return 4;
    }
    Dj(int id, string nombre, int edad, int AñosExperiencia, string apodo, string marcaMezclador) : Artista(id, nombre, edad, AñosExperiencia, apodo), marcaMezclador(marcaMezclador)
    {
    }

    string getmarcaMezclador()
    {
        return marcaMezclador;
    }

    void setmarcaMezclador(string marcaMezclador)
    {
        this->marcaMezclador = marcaMezclador;
    }

    int Salario() override
    {
        return 0;
    }
    void print() override
    {
        Persona::print();
        cout << "ciudad: " << getCiudad() << endl;
    }
    friend ostream &operator<<(ostream &output, Dj &p)
    {
        p.Artista::print();
        output << "ciudad: " << p.getCiudad() << endl;
        return output;
    }
    string getAcento() override
    {
        if (ciudad == "Villavicencio")
        {
            return "pija mano";
        }

        return "no";
    }
    string Presentarse() override
    {
        return "";
    }

    const string &getCiudad() const {
        return ciudad;
    }

    void setCiudad(const string &ciudad) {
        Dj::ciudad = ciudad;
    }
};
class  Musico : public Artista
{
protected:
    //Aca es instrumentoMusico:tipo(instrumento)
    string Instrumento;

public:
    Musico() : Artista()
    {
        Instrumento = "";
    }
    int getTipo() override{
        return 5;
    }
    Musico(int id, string nombre, int edad, int AñosExperiencia, string apodo, string Instrumento) : Artista(id, nombre, edad, AñosExperiencia, apodo), Instrumento(Instrumento)
    {
    }

    string getInstrumento()
    {
        return Instrumento;
    }

    void setInstrumento(string Instrumento)
    {
        this->Instrumento = Instrumento;
    }

    int Salario() override
    {
        return 0;
    }
    void print() override
    {
        Artista::print();
        cout << "El instrumento que toco es: " << getInstrumento() << endl;
    }
    friend ostream &operator<<(ostream &output, Musico &p)
    {
        p.Artista::print();
        output << "El instrumento que toco es:  " << p.getInstrumento() << endl;
        return output;
    }
    string Presentarse() override
    {
        return "";
    }
};

class agrupacionMusical
{
protected:
    string nombre;
    int id;
    int cantidadDeIntegrantes;
    vector<Musico*> Musicos ;

public:
    agrupacionMusical(string nombre, int id, int cantidadDeIntegrantes,vector<Musico*> Musicos ) : nombre(nombre), id(id), cantidadDeIntegrantes(cantidadDeIntegrantes),Musicos(Musicos) {}

    agrupacionMusical()
    {
        this->nombre = "";
        this->id = 0;
        this->cantidadDeIntegrantes = 0;
        this->Musicos={};
    }

    const string &getNombre() const
    {
        return nombre;
    }

    void setNombre(const string &nombre)
    {
        agrupacionMusical::nombre = nombre;
    }

    int getId() const
    {
        return id;
    }

    void setId(int id)
    {
        agrupacionMusical::id = id;
    }

    vector<Musico*> getMusicos()
    {
        return Musicos;
    }

    void setMusicos(vector<Musico*>Musicos)
    {
        this->Musicos=Musicos;
    }

    int getCantidadDeIntegrantes() const
    {
        return cantidadDeIntegrantes;
    }

    void setCantidadDeIntegrantes(int cantidadDeIntegrantes)
    {
        agrupacionMusical::cantidadDeIntegrantes = cantidadDeIntegrantes;
    }

    virtual void tocar()
    {
        cout << "Upss, no sabemos donde esta la agrupacion!!" << endl;
    }
    void print()
    {
        int cont = 0;
        cout << "Nombre De la agrupacion: " << nombre << endl;
        cout << "Id de la agrupacion: " << id << endl;
        cout << "Cantidad de integrantes: " << cantidadDeIntegrantes << endl;
        cout<<"Información de los Musicos: \n"<<endl;
        for(Musico* music1 :Musicos){
            cont+=1;
            cout<<"Informacion Del Musico #"<<cont<<endl;
            cout<<"Id: "<<music1->getId()<<endl;
            cout<< "Nombre del musico: "<<getNombre()<<endl;
            cout<< "Edad: "<<music1->getEdad()<<endl;
            cout<< "Años de experiencia: "<<music1->getAñosExperiencia()<<endl;
            cout<< "Apodo: "<<music1->getApodo()<<endl;
            cout<< "Instrumento que toca: "<<music1->getInstrumento()<<endl<<endl;
        }
    }

    friend ostream &operator<<(ostream &output, agrupacionMusical &m1)
    {
        int cont = 0;
        output << "Nombre: " << m1.nombre << endl;
        output << "Id: " << m1.id << endl;
        output << "Cantidad de integrantes: " << m1.cantidadDeIntegrantes << endl;
        cout<<"Información de los Musicos: \n"<<endl;
        for(Musico* music1 :m1.Musicos){
            cont+=1;
            cout<<"Informacion Del Musico #"<<cont<<endl;
            cout<<"Id: "<<music1->getId()<<endl;
            cout<< "Nombre del musico: "<<m1.getNombre()<<endl;
            cout<< "Edad: "<<music1->getEdad()<<endl;
            cout<< "Años de experiencia: "<<music1->getAñosExperiencia()<<endl;
            cout<< "Apodo: "<<music1->getApodo()<<endl;
            cout<< "Instrumento que toca: "<<music1->getInstrumento()<<endl<<endl;}
        return output;
    }
};
class banda : public agrupacionMusical
{
protected:
    string genero;

public:
    banda(string nombre, int id, int cantidadDeIntegrantes,vector<Musico* > Musicos, string genero) : agrupacionMusical(nombre, id, cantidadDeIntegrantes, Musicos), genero(genero) {}
    banda()
    {
        this->nombre = "";
        this->id = 0;
        this->cantidadDeIntegrantes = 0;
        this->genero = "";
    }

    void tocar() override
    {
        cout << "tumpa tumpa tumpa tumpa" << endl;
    }

    const string &getGenero() const
    {
        return genero;
    }

    void setGenero(const string &genero)
    {
        banda::genero = genero;
    }

    void print()
    {
        agrupacionMusical::print();
        cout << "Genero de la banda: " << genero << "\n\n";
    }
    friend ostream &operator<<(ostream &output, banda &b1)
    {
        b1.agrupacionMusical::print();
        output << "Genero: " << b1.genero << endl;
        return output;
    }
};
class orquesta : public agrupacionMusical
{
protected:
    string TipoOrquesta;

public:
    orquesta(string nombre, int id, int cantidadDeIntegrantes,vector<Musico*> Musico, string tipoOrquesta) : agrupacionMusical(nombre, id, cantidadDeIntegrantes,Musicos), TipoOrquesta(tipoOrquesta) {}

    orquesta()
    {
        this->nombre = "";
        this->id = 0;
        this->cantidadDeIntegrantes = 0;
        this->TipoOrquesta = "";
    }

    const string &getTipoOrquesta() const
    {
        return TipoOrquesta;
    }

    void setTipoOrquesta(const string &tipoOrquesta)
    {
        TipoOrquesta = tipoOrquesta;
    }

    void tocar() override
    {
        cout << "el director de orquesta esta iniciando la obra" << endl;
    }
    void print()
    {
        agrupacionMusical::print();
        cout << "Tipo de orquesta: " << TipoOrquesta << endl;
    }
    friend ostream &operator<<(ostream &output, orquesta &o1)
    {
        o1.agrupacionMusical::print();
        output << "Tipo de orquesta: " << o1.TipoOrquesta << endl;
        return output;
    }
};


class BoletoNormal : public Boletos
{
public:
    BoletoNormal() : Boletos(){}
    BoletoNormal(int idBoletos, string dia, string mes, string anio) : Boletos(idBoletos, dia, mes, anio){}


    int getTipoBoleto() override{
        return 1;
    }
    friend ostream &operator<<(ostream &output, BoletoNormal &p)
    {
        p.Boletos::print();
        return output;
    }

    string Manilla()override
    {
        return "manilla roja";
    }
};


class BoletoMedia : public Boletos
{
protected:
    string merchandising;
public:
    BoletoMedia() : Boletos()
    {

    }
    BoletoMedia(int idBoletos, string dia,string mes, string año,string merchandising) : Boletos(idBoletos, dia,mes,año),merchandising(merchandising)
    {
    }

    int getTipoBoleto() override{
        return 2;
    }


    friend ostream &operator<<(ostream &output, BoletoMedia &p)
    {
        p.Boletos::print();
        return output;
    }

    string Manilla()override
    {
        return "manilla roja";
    }

    const string &getMerchandising() const {
        return merchandising;
    }

    void setMerchandising(const string &merchandising) {
        BoletoMedia::merchandising = merchandising;
    }
};
class BoletoVip : public Boletos
{
protected:
    string merchandising = "";
    bool backStage = true;

public:
    BoletoVip() : Boletos()
    {

    }
    BoletoVip(int idBoletos, string dia, string mes, string anio, string merchandising, bool backStage) : Boletos(idBoletos, dia, mes, anio), merchandising(merchandising), backStage(backStage)
    {
    }

    int getTipoBoleto()override{
        return 3;
    }

    friend ostream &operator<<(ostream &output, BoletoVip &p)
    {
        p.Boletos::print();
        output<<p.merchandising<<endl;
        if(p.backStage == true){
            output<<"Puede entrar al backStage";
        }
        return output;
    }

    string Manilla()override
    {
        return "manilla roja";
    }
};

class VIP{
protected:
    BoletoVip boletoVIP;
public:
    BoletoVip getBoletoVIP()
    {
        return boletoVIP;
    }
    void setBoletoVIP(int idBoleto, string dia, string mes, string anio, string merchandising, bool backstage)
    {
        boletoVIP = BoletoVip(idBoleto, dia, mes, anio, merchandising,backstage);
    }
};


class producto : public Distribuidora
{
protected:
    string nombre;
    int precio;

public:
    producto() : Distribuidora()
    {
        nombre = "";
        precio = 0;
    }
    producto(string Marca, string nombre, int precio) : Distribuidora(Marca), nombre(nombre), precio(precio)
    {
    }

    string getnombre()
    {
        return nombre;
    }

    void setnombre(int nombre)
    {
        this->nombre = nombre;
    }

    int getprecio()
    {
        return precio;
    }

    void setprecio(int precio)
    {
        this->precio = precio;
    }

    void print()
    {
        Distribuidora::print();
        cout << "nombre " << getnombre() << endl;
        cout << "precio: " << getprecio() << endl;
    }

    friend ostream &operator<<(ostream &output, producto &p)
    {
        p.Distribuidora::print();
        output << "nombre " << p.getnombre() << endl;
        output << "precio: " << p.getprecio() << endl;
        return output;
    }

    string getFrase()=0;


    virtual void consumo()=0;

};

class comida: public producto{
protected:
    int calorias;
public:
    comida(string nombre, int precio,string marca, int calorias):producto(marca,nombre,precio), calorias(calorias){}

    comida(){
        this->nombre = "";
        this->precio = 0;
        this->Marca = "";
        this->calorias = 0;
    }

    int getCalorias() const {
        return calorias;
    }

    void setCalorias(int calorias) {
        comida::calorias = calorias;
    }

    string getFrase()override{
        string fraseComida = "Barriga llena, corazon contento";
        cout<< fraseComida<<endl;
        return fraseComida;
    }

    void consumo()override{
        cout<< "Comiendo....  (sonido de minecraft**)"<<endl;
    }

    void print() {
        producto::print();
        cout<< "caloritas: "<<getCalorias();
    }

    friend ostream &operator<<(ostream &output, comida &c1){
        c1.producto::print();
        output<<"Calorias: "<<c1.calorias<<endl;
        return output;
    }

};

class bebida: public producto{
protected:
    int azucar;
public:
    bebida(string nombre, int precio,string marca, int azucar):producto(marca,nombre,precio),azucar(azucar){}

    bebida(){
        this->Marca="";
        this->nombre="";
        this->precio=0;
        this->azucar=0;
    }

    int getAzucar() const {
        return azucar;
    }

    void setAzucar(int azucar) {
        bebida::azucar = azucar;
    }

    string getFrase() override{
        string fraseBebida = "Coca-Cola ;))";
        cout<< fraseBebida<<endl;
        return fraseBebida;
    }
    
    void consumo()override{
        cout<< "bebiendo... (glu glu glu)"<<endl;
    }

};

class VendedorTienda{
protected:
    int idTienda;
    string nombre;
    vector<producto*> productoInventario;
public:
    VendedorTienda(){
        idTienda = 0;
        nombre = "";
        productoInventario = {};
    }
    VendedorTienda(int idTienda, string nombre, vector<producto*> productoInventario): idTienda(idTienda), nombre(nombre), productoInventario(productoInventario){}

    int getIdTienda() const {
        return idTienda;
    }

    void setIdTienda(int idTienda) {
        VendedorTienda::idTienda = idTienda;
    }

    const string &getNombre() const {
        return nombre;
    }

    void setNombre(const string &nombre) {
        VendedorTienda::nombre = nombre;
    }

    const vector<producto *> &getProductoInventario() const {
        return productoInventario;
    }

    void setProductoInventario(const vector<producto *> &productoInventario) {
        VendedorTienda::productoInventario = productoInventario;
    }

    friend ostream& operator<<(ostream &out, VendedorTienda &v){
        out << "Nombre: " << v.nombre << endl;
        out << "Id de Tienda: " << v.idTienda << endl;
        out << "Productos: " << endl;

        int contador = 1;
        for (producto* p : v.productoInventario ){
            cout << "Producto " <<contador << ")"<< endl;
            p->print();
            contador++;
        }
        return out;
    }

    };


class Seguridad : public Persona
{
protected:
    bool ExperienciaPeleando;
    string Turno;

public:
    Seguridad() : Persona()
    {
        ExperienciaPeleando = 0;
        Turno = "";
    }
    int getTipo() override{return 6;}
    Seguridad(int id, string nombre, int edad, bool ExperienciaPeleando, string Turno) : Persona(id, nombre, edad), ExperienciaPeleando(ExperienciaPeleando), Turno(Turno)
    {
    }

    bool getExperienciaPeleando()
    {
        return ExperienciaPeleando;
    }

    void setExperienciaPeleando(bool ExperienciaPeleando)
    {
        this->ExperienciaPeleando = ExperienciaPeleando;
    }

    string getTurno()
    {
        return Turno;
    }

    void setTurno(string Turno)
    {
        this->Turno = Turno;
    }

    int Salario() override
    {
        return 0;
    }
    void print() override
    {
        Persona::print();
        cout << "Años Experiencia Peleando " << getExperienciaPeleando() << endl;
        cout << "turno del dia: " << getTurno() << endl;
    }

    friend ostream &operator<<(ostream &output, Seguridad &p)
    {
        p.Persona::print();
        output << "Años Experiencia peleando " << p.getExperienciaPeleando() << endl;
        output << "turno del dia: " << p.getTurno() << endl;
        return output;
    }
};

class Empresa{
protected:
    string nombre;
    int anioDeCreacion;
public:
    Empresa(){
        nombre = "";
        anioDeCreacion = 0;
    }
    Empresa(string nombre, int anioDeCreacion): nombre(nombre), anioDeCreacion(anioDeCreacion){}

    string getNombre()
    {
        return nombre;
    }

    void setNombre(string nombre)
    {
        this->nombre = nombre;
    }
    int getAnioDeCreacion()
    {
        return anioDeCreacion;
    }

    void setAnioDeCreacion(int anioDeCreacion)
    {
        this->anioDeCreacion = anioDeCreacion;
    }
};

class Patrocinador : public Persona
{
protected:
    //
    Empresa empresaPatrocinadora;

public:
    Patrocinador() : Persona(){this->empresaPatrocinadora = Empresa();}
    int getTipo() override{
        return 7;
    }
    Patrocinador(int id, string nombre, int edad, string NombreEmpresa, int añoDeCracion) : Persona(id, nombre, edad)
    {this->empresaPatrocinadora = Empresa(NombreEmpresa,añoDeCracion);
    }

    int Salario() override
    {
        return 0;
    }
    void print() override
    {
        Persona::print();

        cout << "Empresa: " << empresaPatrocinadora.getNombre() << endl;
        cout<< empresaPatrocinadora.getAnioDeCreacion();
    }
    friend ostream &operator<<(ostream &output, Patrocinador &p)
    {
        p.Persona::print();

        output << "Empresa: " << p.empresaPatrocinadora.getNombre() << endl;
        output<<p.empresaPatrocinadora.getAnioDeCreacion()<<endl;
        return output;
    }

    const Empresa &getEmpresaPatrocinadora() const {
        return empresaPatrocinadora;
    }

    void setEmpresaPatrocinadora(const Empresa &empresaPatrocinadora) {
        Patrocinador::empresaPatrocinadora = empresaPatrocinadora;
    }
};

class Marketing : public Persona
{
protected:
    int Experiencia;

public:
    Marketing() : Persona()
    {
        Experiencia = 0;
    }
    int getTipo() override{
        return 8;
    }
    Marketing(int id, string nombre, int edad, int Experiencia) : Persona(id, nombre, edad), Experiencia(Experiencia)
    {
    }

    int getExperiencia()
    {
        return Experiencia;
    }

    void setExperiencia(int Experiencia)
    {
        this->Experiencia = Experiencia;
    }

    int Salario() override
    {
        return 0;
    }
    void print() override
    {
        Persona::print();
        cout << "Experiencia " << getExperiencia() << endl;
    }
    friend ostream &operator<<(ostream &output, Marketing &p)
    {
        p.Persona::print();
        output << "Experiencia" << p.getExperiencia() << endl;
        return output;
    }
};

class securityStaff{
public:
        virtual string usoDeArmas() = 0;

};//interfaz

class  seguridad: public Persona,public securityStaff{
protected:
    bool experienciaPelea;
    string turno;
public:
    seguridad(string nombre, int id, int edad, bool experienciaPelea, string turno):Persona(id,nombre, edad), experienciaPelea(experienciaPelea), turno(turno){}

    seguridad(){
        this-> nombre = "";
        this->id = 0;
        this->edad = 0;
        this->experienciaPelea = true;
        this->turno = "";
    }
    int getTipo() override{
        return 9;
    }

    bool isExperienciaPelea() const {
        return experienciaPelea;
    }

    void setExperienciaPelea(bool experienciaPelea) {
        seguridad::experienciaPelea = experienciaPelea;
    }

    const string &getTurno() const {
        return turno;
    }

    void setTurno(const string &turno) {
        seguridad::turno = turno;
    }

    int Salario()override{
        return 0;
    }

    string usoDeArmas() override{
        string arma = "tengo bolillo";
        cout<< arma<<endl;
        return arma;
    }

    void print(){
        Persona::print();
        cout << experienciaPelea<<endl;
        cout << turno<<endl;
    }

    friend ostream &operator << (ostream &output, seguridad &s){
        s.Persona::print();
        output << s.experienciaPelea << endl;
        output << s.turno << endl;
        return output;
    }

};

class Policia : public Persona, public Movilizacion, public securityStaff
{
protected:
    string identificacionPolicial;

public:
    Policia(int id, string nombre, int edad, string identificacionPolicial) : Persona(id, nombre, edad), identificacionPolicial(identificacionPolicial) {}

    int getTipo() override{return 10;}
    string getIdentificacionPolicial()
    {
        return identificacionPolicial;
    }
    void setIdentificacionpolicial(string identificacionPolicial)
    {
        this->identificacionPolicial = identificacionPolicial;
    }

    int Salario() override
    {
        return 0;
    }
    string TipoVehiculo() override
    {
        return "Motora ";
    }
    string usoDeArmas() override{
        string armas = "Tengo un revolver";
        cout<< armas<< endl;
        return armas;
    }
    friend ostream& operator <<(ostream &output, Policia &p)
    {
        p.Persona::print();
        output << "Identificacion Policial: " << p.getIdentificacionPolicial() << endl;
        return output;
    }
};

class FuerzaPolicial
{
protected:
    string Rango;
    string Cuadrante;
    vector<Policia*> policias;

public:
    FuerzaPolicial()
    {
        Rango = "";
        Cuadrante = "";
        policias = {};
    }
    FuerzaPolicial(string Rango, string Cuadrante, vector<Policia*> policias) : Rango(Rango), Cuadrante(Cuadrante), policias(policias)
    {
    }

    string getRango()
    {
        return Rango;
    }

    void setRango(string Rango)
    {
        this->Rango = Rango;
    }

    string getCuadrante()
    {
        return Cuadrante;
    }

    void setCuadrante(string Cuadrante)
    {
        this->Cuadrante = Cuadrante;
    }

    vector<Policia*> getPolicias()
    {
        return policias;
    }

    void setPolicias(vector<Policia*> policias)
    {
        this->policias = policias;
    }

    int getSalario()
    {
        return 0;
    }
    void print()
    {
        cout << "Rango es" << getRango() << endl;
        cout << "el cuadrante es: " << getCuadrante() << endl;
        cout << "Hombres: " << endl;
        for(Policia* plc : policias)
        {
            cout << *plc << endl;
        }
    }
    friend ostream &operator<<(ostream &output, FuerzaPolicial &p)
    {
        output << "Rango es " << p.getRango() << endl;
        output << "el cuadrante es:: " << p.getCuadrante() << endl;
        output << "Hombres: " << endl;
        for(Policia* plc : p.getPolicias())
        {
            output << *plc << endl;;
        }

        return output;
    }

    string TipoVehiculo()
    {
        return "moto";
    }
};

class Evento : public Lugar, public Ubicacion, public Efectos
{
protected:
    string Titulo;
    int TiendasDisponibles;
    vector <VendedorTienda*> vendedores;
    Fecha fecha;


public:
    Evento() : Lugar(), Ubicacion()
    {
        Titulo = "";
        TiendasDisponibles = 0;
        vendedores = {};
        fecha = Fecha();
    }
    Evento(string NombreLugar, double CapacidadMinima, double CapacidadMaxima, string Direccion,
           string Ciudad, string Titulo, int TiendasDisponibles, vector<VendedorTienda*> vendedores,string dia, string mes, string anio) :
            Lugar(NombreLugar, CapacidadMinima, CapacidadMaxima), Ubicacion(Direccion, Ciudad), Titulo(Titulo),
            TiendasDisponibles(TiendasDisponibles), vendedores(vendedores){
        this->fecha = Fecha(dia,mes,anio);
    }

    string getTitulo()
    {
        return Titulo;
    }

    void setTitulo(string Titulo)
    {
        this->Titulo = Titulo;
    }
    int getTiendasDisponiblesTitulo()
    {
        return TiendasDisponibles;
    }

    void setTiendasDisponibles(int TiendasDisponibles)
    {
        this->TiendasDisponibles = TiendasDisponibles;
    }

    vector<VendedorTienda*> getVendedores()
    {
        return vendedores;
    }
    void setVendedores(vector<VendedorTienda*> vendedores)
    {
        this->vendedores = vendedores;
    }

    Fecha getFecha(){
        return fecha;
    }
    void setFecha(){
        this->fecha = Fecha();
    }

    void print()
    {
        Lugar::print();
        Ubicacion::print();
        cout << "Nombre del Evento: " << getTitulo() << endl;
        cout << "Cantidad de tiendas en evento: " << getTiendasDisponiblesTitulo() << endl;
        cout << "Vendedores: " << endl;
        int contador = 1;
        for(VendedorTienda* v: vendedores)
        {
            cout << "Vendedor " << contador << endl;
            cout << *v;
            contador++;
        }
        cout << "Fecha: " << fecha;
    }
    friend ostream &operator<<(ostream &output, Evento &p)
    {
        p.Lugar::print();
        p.Ubicacion::print();
        output << "Nombre del Evento: " << p.getTitulo() << endl;
        output << "Cantidad de tiendas en evento: " << p.getTiendasDisponiblesTitulo() << endl;
        int contador = 1;
        for(VendedorTienda* v: p.vendedores)
        {
            output << "Vendedor " << contador << endl;
            output << *v;
            contador++;
        }
        output << "Fecha: " << p.fecha;

        return output;
    }

    bool ShowFuego() override
    {
        return true;
    }
    bool ShowLuces() override
    {
        return true;
    }
};

class Logistica : public Empleado
{
protected:
    string cargo;

public:
    Logistica() : Empleado()
    {
        cargo = "";
    }
    int getTipo() override{
        return 11;
    }
    Logistica(int id, string nombre, int edad, int idTrabajador, string Usuario, string Contraseña, string cargo) : Empleado(id, nombre, edad, idTrabajador, Usuario, Contraseña), cargo(cargo)
    {
    }

    string getcargo()
    {
        return cargo;
    }

    void setcargo(string cargo)
    {
        this->cargo = cargo;
    }

    void print()
    {
        Empleado::print();
        cout << "El cargo es " << getcargo() << endl;
    }
    friend ostream &operator<<(ostream &output, Logistica &p)
    {
        p.Empleado::print();
        output << "El cargo es " << p.getcargo() << endl;
        return output;
    }
    bool login() override
    {
        return true;
    }
    string turno() override
    {
        return "Diario";
    }

    string getTipoContrato () override{
         return "Contrato Logistico: Nomina Tiempo Completo";
    }
};

class VendedorEntradas : public Empleado
{
protected:
    vector<Boletos*> boleteria;
public:
    VendedorEntradas(): Empleado(){
        this->boleteria = {};
    }
    VendedorEntradas(int id, string nombre, int edad, int idTrabajador, string Usuario, string Contraseña, vector<Boletos*> boleteria):
                    Empleado(id, nombre, edad, idTrabajador, Usuario, Contraseña), boleteria(boleteria){}
    vector<Boletos*> getBoleteria()
    {
        return boleteria;
    }
    void setBoleteria(vector<Boletos*>boleteria)
    {
        VendedorEntradas::boleteria = boleteria;
    }

    int getTipo() override{
    return 12;
    }
    
    string getTipoContrato()override
    {
        return "Contrato por nomina\n";
    }

    string turno()override
    {
        return "Diario\n";
    }
    void print()
    {
        Empleado::print();
        cout << getTipoContrato() << endl;
        int contador = 1;
        string tipo;
        for(Boletos* b: boleteria)
        {
            b->print();
        }
    }
    friend ostream& operator <<(ostream& output, VendedorEntradas vE)
    {
        vE.Empleado::print();
        output << vE.getTipoContrato() << endl;
        int contador = 1;
        string tipo;
        cout << "Boletos: " << endl;
        for(Boletos* b: vE.boleteria)
        {
            output << contador << ")";
            if(b->getTipoBoleto()==1)
            {
                tipo = "Normal";
            }
            else if(b->getTipoBoleto()==2)
            {
                tipo = "Medio";
            }
            else
            {
                tipo = "VIP";
            }
            output << "Boleto " << tipo << endl;
            output << *b << endl;
        }
        return output;
    }

    };

class Espectador : public Persona, public Pago, public MetodoPago
{
protected:
    string correo;
    vector<Boletos*> boletos;
public:
    Espectador():Persona(), correo(""), boletos(0){}
    Espectador(string nombre,int id, int edad,string correo, vector<Boletos*> boletos):
                Persona(id,nombre,edad), correo(correo), boletos(boletos){}

    string getCorreo(){
        return correo;
    }

    void setCorreo(string correo)
    {
        Espectador::correo = correo;
    }

    vector<Boletos*> getBoletos()
    {
        return boletos;
    }

    void setBoletos(vector<Boletos*> boletos)
    {
        Espectador::boletos = boletos;
    }
    int getTipo() override{
        return 13;
    }

    int Salario()override{
        return 0;
    }

    bool ComprarBoleta()override{
        return true;
    }

    bool Tarjeta() override{
        return true;}

    bool Efectivo(){
        return true;
    } 
    bool Nequi()override{
        return false;
    }
    
    void print(){
        Persona::print();
        cout<< "Correo: "<< this->correo;
        cout << "Boletos: " << endl;
        int contador = 1;
        for(Boletos* b : boletos)
        {
            cout << contador << ") " << endl;
            cout << *b;
            contador++;
        }

    }

    friend ostream &operator<<(ostream &output, Espectador &e1){
        e1.Persona::print();
        output << "Correo: "<<e1.correo;
        output << "Boletos: " <<endl;
        int contador = 1;
        for(Boletos* b : e1.boletos)
        {
            output << *b;
        }
        return output;
    }
};

class Tarima{
protected:
    vector<Artista*> presentacionArtistas;
    vector<agrupacionMusical*> presentacionAgrupacion;
public:
    Tarima(): presentacionArtistas(0), presentacionAgrupacion(0){}
    Tarima(vector<Artista*> presentacionArtistas, vector<agrupacionMusical*> presentacionAgrupacion): presentacionArtistas(presentacionArtistas), presentacionAgrupacion(presentacionAgrupacion){}
};

int main()
{   vector<Artista*> listaArtista = {};
    vector<agrupacionMusical*> listaAgrupacion = {};
    vector<producto*> inventario = {};
    vector<Empleado*> listaEmpleados = {};
    vector<Marketing*> PersonalMarketing ={};
    vector <Musico*> musicians = {};
    vector<Boletos*> boleterias = {};
    vector<Patrocinador*> patro = {};
    vector<Espectador*> especta = {};
//vector de policia
//vector de seguridad





    string festival = "";
    int opc = 0;
    while(opc != 10){
        cout<<"1. Agregar una agrupacion musical\n"
              "2. crear Nuevo evento\n"
              "3. Agregar un patrocinador.\n"
              "4. Agregar un Artista\n"
              "5. Agregar Personal de Marketing\n"
              "6. Agregar un Empleado\n"
              "7. Agregar un espectador\n"
              "8. Agregar seguridad al evento\n"
              "9. Espectaculo\n "
              "10.Salir"
              "Ingrese una opción";
        cin>>opc;

            if(opc == 1){
                int opcAgrupacionMusical = 0;
                cout<< "1. Banda\n2.Orquesta\nIngrese una opcion: ";
                cin>>opcAgrupacionMusical;


                if(opcAgrupacionMusical == 1) {
                    int id = 0,numIntegrantes=0, contAM=1,edadMusico = 0,añosExpMusico = 0,idMusico=0;
                    string nombre = "",nombreMusico,apodoMusico,instrumento,genero;



                    cout << "genial, agregaremos una banda al " + festival + " pero necesitamos su informacion\n"
                    "Ingresa el nombre de la banda: ";
                    cin>>nombre;
                    cout<< "ingresa el id de la banda: .";
                    cin>>id;
                    cout<< "Cuantos musicos contiene la banda??";
                    cin>>numIntegrantes;
                    cout<< "ahora tenemos que agregar la información de los musicos";
                    for (int i = 1;i<=numIntegrantes;i++) {
                        cout<< "INFORMACION DEL MUSICO #"<<contAM<<endl;
                        cout<< "Ingrese el Id: ";
                        cin>>idMusico;
                        cout<< "Ingrese el nombre: ";
                        cin>>nombreMusico;
                        cout<< "ingrese la edad del musico: ";
                        cin>>edadMusico;
                        cout<< "Ingrese los años de experiencia";
                        cin>>añosExpMusico;
                        cout<< "Ingrese el apodo del: ";
                        cin>>apodoMusico;
                        cout<< "instrumento musical: ";
                        cin>>instrumento;
                        musicians.push_back(new Musico(idMusico,nombreMusico,edadMusico,añosExpMusico,apodoMusico,instrumento) );
                        cout<< "EL MUSICO #" << contAM << "FUE AGREGADO!"<<endl;
                        contAM++;
                    }
                    cout<< "solo falta el genero de la banda: ";
                    cin>>genero;
                    agrupacionMusical *a1 = new banda(nombre,id,numIntegrantes,musicians,genero);
                }
                else if(opcAgrupacionMusical==2){
                    int id = 0,numIntegrantes=0, contAM=1,edadMusico = 0,añosExpMusico = 0,idMusico=0;
                    string nombre = "",nombreMusico,apodoMusico,instrumento,tipoOrquesta;
                    vector <Musico*> musicians = {};

                    cout << "genial, agregaremos una Orquesta al " + festival + " pero necesitamos su informacion\n"
                                                                             "Ingresa el nombre de la orquesta: ";
                    cin>>nombre;
                    cout<< "ingresa el id de la orquesta: .";
                    cin>>id;
                    cout<< "Cuantos musicos contiene la orquesta??";
                    cin>>numIntegrantes;
                    cout<< "ahora tenemos que agregar la información de los musicos";
                    for (int i = 1;i<=numIntegrantes;i++) {
                        cout<< "INFORMACION DEL MUSICO #"<<contAM<<endl;
                        cout<< "Ingrese el Id: ";
                        cin>>idMusico;
                        cout<< "Ingrese el nombre: ";
                        cin>>nombreMusico;
                        cout<< "ingrese la edad del musico: ";
                        cin>>edadMusico;
                        cout<< "Ingrese los años de experiencia";
                        cin>>añosExpMusico;
                        cout<< "Ingrese el apodo del: ";
                        cin>>apodoMusico;
                        cout<< "instrumento musical: ";
                        cin>>instrumento;
                        musicians.push_back(new Musico(idMusico,nombreMusico,edadMusico,añosExpMusico,apodoMusico,instrumento) );
                        cout<< "EL MUSICO #" << contAM << "FUE AGREGADO!"<<endl;
                        contAM++;
                    }
                        cout<< "ahora solo falta el tipo de orquesta: ";
                        cin>>tipoOrquesta;
                        agrupacionMusical *a1 = new orquesta(nombre,id,numIntegrantes,musicians,tipoOrquesta);
                }

        }

            else if(opc == 2){
                //-------falta la composición------//


                string nombreLugar = "",direccion = "",ciudad = "",titulo = "";
                double capacidadMinima = 0,capacidadMaxima = 0;
                int TiendasDisponibles = 0;
                cout<< "HOLAA!!, Aca planearemos nuestro festival"<<endl;
                cout<< "Pero primero necesitamos un nombre para este"<<endl;
                cout<< "por favor, ingresa el nombre del festival: ";
                cin>>festival;
                cout<< "\nAHORA PODREMOS DAR LA BIENVENIDA AL FESTIVAL "+festival<<endl;
                cout<< "pero necesitamos hacer la preparación del evento\n\n";
                cout<< "iniciaremos con las cosas indispensables"<<endl;

                cout<< "Para crear el evento necesitamos la siguiente informacion: "<<endl;
                cout<< "Nombre del lugar donde se hara el "+festival<<": "<<endl;
                cin>>nombreLugar;
                cout<< "Capacidad minima: ";
                cin>>capacidadMinima;
                cout<< "Capacidad maxima: ";
                cin>>capacidadMaxima;
                cout<< "Direccion del evento: ";
                cin>>direccion;
                cout<< "Ciudad del evento: ";
                cin>>ciudad;
                cout<< "titulo o slogan: ";
                cin>>titulo;
                cout<< "Numero de tiendas disponibles";
                cin>>TiendasDisponibles;
                //Evento ev = Evento(nombreLugar,capacidadMinima,capacidadMaxima,direccion,ciudad,titulo,TiendasDisponibles);

            }

            else if(opc == 3){
                string nombreEmpresa = "",nombre = "";
                int añoDeCreacion = 0;
                int edad, id;
                cout<< "Genial!!, conseguiste un patrocinador, pero ahora necesitamos su información"<<endl;
                
                cout<< "Ingresa el nombre del patrocinador"<<endl;
                cin>>nombre;
                cout<< "Ingresa la edad: "<<endl;
                cin>>edad;
                cout<< "Ingrese el id: "<<endl;
                cin>>id;
                cout<< "Nombre de la empresa a la que pertenece: "<<endl;
                cin>>nombreEmpresa;
                cout<< "Año de creacion de la empresa";
                cin>>añoDeCreacion;
                
                Patrocinador p1 = Patrocinador(id,nombre,edad,nombreEmpresa,añoDeCreacion);
                
                cout<< "Perfecto, se a agregado el patrocinador "<<p1.getnombre()<<endl;
            }

            else if(opc == 4){
                int opcArtista = 0,id = 0,edad = 0,añosDeExperiencia = 0;
                string instrumento="",genero="",nombre="",apodo="", marcaMezclador = "";
                cout<< "Seleccione una de las siguientes opciones:  "<<endl;
                cout<<  "1.Crear un musico \n2.Crear un Cantante\n 3. Crear un dj "<<endl;
                cin>>opcArtista;
                if(opcArtista == 1){
                    cout<< "--------AGREGAR MUSICOS--------"<<endl;
                    cout<< "Agregue el nombre del musico"<<endl;
                    cin>>nombre;
                    cout<< "Agregue el id: "<<endl;
                    cin>>id;
                    cout<< "Agregue la edad del musico: "<<endl;
                    cin>>edad;
                    cout<< "Agregue el apodo: "<<endl;
                    cin>>apodo;
                    cout<< "Agregue años de experiencia: "<<endl;
                    cin>> añosDeExperiencia;
                    cout<<"Agregue el nombre del instrumento: "<<endl;
                    cin>>instrumento;

                    listaArtista.push_back(new Musico(id,nombre,edad,añosDeExperiencia,apodo,instrumento));
                    cout<< "Se ha agregado el musico! ;)"<<endl;
                }
                else if(opcArtista == 2){
                    cout<< "--------AGREGAR CANTANTES--------"<<endl;
                    cout<< "Agregue el nombre del cantante"<<endl;
                    cin>>nombre;
                    cout<< "Agregue el id: "<<endl;
                    cin>>id;
                    cout<< "Agregue la edad del cantante: "<<endl;
                    cin>>edad;
                    cout<< "Agregue el apodo: "<<endl;
                    cin>>apodo;
                    cout<< "Agregue años de experiencia: "<<endl;
                    cin>> añosDeExperiencia;
                    cout<<"Agregue el nombre del instrumento: "<<endl;
                    cin>>genero;

                    listaArtista.push_back(new Cantante(id,nombre,edad,genero,añosDeExperiencia,apodo));
                    cout<< "Se ha agregado el cantante ;))"<<endl;
                }
                else if(opcArtista == 3) {
                    cout << "--------AGREGAR UN PATROCINADOR--------" << endl;
                    string nombre= "",nombreEmpresa = "";
                    int id = 0, edad = 0,añoDeCreacion = 0;
                    cout<< "Ingrese el nombre del patrocinador"<<endl;
                    cin>>nombre;
                    cout<<"Ingrese el id: "<<endl;
                    cin>>id;
                    cout<< "Ingrese la edad del patrocinador"<<endl;
                    cin>>edad;
                    cout<< "Ingrese el nombre de la empresa del patrocinador: "<<endl;
                    cin>>nombreEmpresa;
                    cout<< "Ingrese el año de creacion de la empresa: "<<endl;
                    cin>>añoDeCreacion;

                    patro.push_back(new Patrocinador(id,nombre,edad,nombreEmpresa,añoDeCreacion));
                    cout<< "el patrocinador ha sido agregado";
                }
            }

            else if(opc == 5){
                int id = 0, edad = 0,experiencia = 0;
                string nombre = "";
                cout << "--------AGREGAR UN PERSONAL DE MARKETING--------" << endl;

                cout<< "Agregue el nombre del musico"<<endl;
                cin>>nombre;
                cout<< "Agregue el id: "<<endl;
                cin>>id;
                cout<< "Agregue la edad del musico: "<<endl;
                cin>>edad;
                cout<< "ingrese Años de experiencia"<<endl;
                cin>>experiencia;

                PersonalMarketing.push_back(new Marketing(id,nombre,edad,experiencia));
                cout<< "Personal de marketing creado ;))";
            }

            else if(opc == 6){
                string nombre = "", usuario = "", contraseña = "";
                int id = 0, edad = 0, idTrabajador = 0, opcEmpleado = 0, opcVendedor = 0;
                cout << "--------AGREGAR UN EMPLEADO--------" << endl<<endl;
                cout << "Seleccione una de las siguientes opciones:" << endl;
                cout << "1. Crear empleado logistico \n2. Crear Vendedor de entrada"<<endl;
                cin >> opcEmpleado;
                if (opcEmpleado == 1){
                    cout << "--------AGREGAR UN EMPLEADO LOGISTICO--------" << endl;
                    cout << "ingresa la identificacion del empleado: "<<endl;
                    cin >> id;
                    cout << "Agrega el nombre del empleado: "<<endl;
                    cin >> nombre;
                    cout <<"Escribe la edad del empleado"<<endl;
                    cin >> edad;
                    cout << "Agrega el ID del empleado: "<<endl;
                    cin >> idTrabajador;
                    cout << "Agrega el nombre de usuario para el empleado: "<<endl;
                    cin >> usuario;
                    cout << "Escribe la contraseña del empleado: " <<endl;
                    cin >> contraseña;


                }
                else if(opcEmpleado == 2){
                    int itBoleto = 0;
                    cout << "--------AGREGAR UN VENDEDOR DE ENTRADAS--------" << endl;
                    cout << "ingresa la identificacion del vendedor de entradas: "<<endl;
                    cin >> id;
                    cout << "Agrega el nombre del vendedor de entradas: "<<endl;
                    cin >> nombre;
                    cout <<"Escribe la edad del vendedor de entradas"<<endl;
                    cin >> edad;
                    cout << "Agrega el ID del vendedor de entradas: "<<endl;
                    cin >> idTrabajador;
                    cout << "Agrega el nombre de usuario para el vendedor de entradas: "<<endl;
                    cin >> usuario;
                    cout << "Escribe la contraseña del vendedor de entradas: " <<endl;
                    cin >> contraseña;
                    cout<< "cuantos boletos tiene el vendedor?"<<endl;
                    for(int i = 0; i <= itBoleto;i++){
                        cout << "Seleccione una de las siguientes opciones:" << endl;
                        cout<<"1. Boleto normal\n2.Boleto media\n3. Boleto vip"<<endl;
                        cin >> opcVendedor;
                        if(opcVendedor == 1){
                            int idBoleto = 0, valor = 0;
                            string dia = "", mes, anio;
                            cout<< "ingrese el id del boleto"<<endl;
                            cin >> idBoleto;
                            cout << "Ingrese el dia de la fecha de caducidad del boleto: "<<endl;
                            cin>>dia;
                            cout<< "Ingrese el mes de la fecha de caducidad del boleto: "<<endl;
                            cin>>mes;
                            cout<< "Ingrese el año de la fecha de caducidad del boleto: "<<endl;
                            cin>>anio;
                            cout << "Ingresa el valor del boleto: "<<endl;
                            cin >> valor;
                            boleterias.push_back(new BoletoNormal(id,dia,mes,anio));

                        }else if(opcVendedor == 2){
                            int idBoleto = 0, valor = 0;
                            string dia = "", mes, anio,merchandising;
                            cout<< "ingrese el id del boleto"<<endl;
                            cin >> idBoleto;
                            cout << "Ingrese el dia de la fecha de caducidad del boleto: "<<endl;
                            cin>>dia;
                            cout<< "Ingrese el mes de la fecha de caducidad del boleto: "<<endl;
                            cin>>mes;
                            cout<< "Ingrese el año de la fecha de caducidad del boleto: "<<endl;
                            cin>>anio;
                            cout << "Que merchandising recibe?: "<<endl;
                            cin >> merchandising;

                            boleterias.push_back(new BoletoMedia(id,dia,mes,anio,merchandising));
                        }else if(opcVendedor == 3 ){

                            int idBoleto = 0, valor = 0;
                            string dia = "", mes, anio, merchandising;
                            bool backStage = true;
                            cout<< "ingrese el id del boleto"<<endl;
                            cin >> idBoleto;
                            cout << "Ingrese el dia de la fecha de caducidad del boleto: "<<endl;
                            cin>>dia;
                            cout<< "Ingrese el mes de la fecha de caducidad del boleto: "<<endl;
                            cin>>mes;
                            cout<< "Ingrese el año de la fecha de caducidad del boleto: "<<endl;
                            cin>>anio;
                            cout << "Ingresa el valor del boleto: "<<endl;
                            cin >> valor;
                            cout << "El merchandising para boleteria VIP es una camiseta"<<endl;
                            cout << "Deseas entrar en el BackStage: "<<endl;
                            cout << "  0) no,    1)si"<<endl;
                            cin >> backStage;

                            boleterias.push_back(new BoletoVip(id,dia,mes,anio,"no", true));
                        }
                    }

                }
            }
            else if(opc == 7){
                string nombre = "", correo ="";
                int id = 0, edad = 0;
                cout << "--------AGREGAR ESPECTADORES--------" << endl<<endl;
                cout << "Crearemos ahora a los espectadores que asistiran al concierto"<<endl;
                cout << "Ingrese el ID del espectador: "<<endl;
                cin >> id;
                cout << "Ingrese el nombre del espectador: "<<endl;
                cin >> nombre;
                cout << "Ingresa la edad del espectador: "<<endl;
                cin >> edad;
                cout << "Ingrese el correo del espectador: "<<endl;
                cin >> correo;
                cout << ""
                especta.push_back(new Espectador(nombre,id, edad, correo,))



            }
            else if(opc == 8){
                string nombre = "";
                int id = 0, edad = 0, opcSeguridad = 0;

                cout << "--------AGREGAR SEGURIDAD AL EVENTO--------" << endl<<endl;
                cout << "Ahora seleccionaremos a los que se encargaran de la seguridad del evento"<< endl;
                cout << "Seleccione una de las siguientes opciones: "<<endl;
                cout << "1. Seguridad\n2. Fuerza policial"<<endl<<endl;
                cin >> opcSeguridad;

                if (opcSeguridad == 1){
                    int nSeguridad;
                    cout << "Cuantos hombres de seguridad quiere agregar? " << endl;
                    cin >> nSeguridad;
                    for(int i = 1; i<=nSeguridad, i++)
                    {
                        cout << "--------SEGURIDAD--------" << endl<<endl;
                        cout << "Seguridad (" << i << ")" << endl;
                        cout << "Ingresa el nombre: "<<endl;
                        cin >> nombre;
                        cout >>
                    }
                }
                else if(opcSeguridad == 2){
                    cout << "";
                }
            }
            else if(opc == 9){
                
            }

    }


    return 0;
}
