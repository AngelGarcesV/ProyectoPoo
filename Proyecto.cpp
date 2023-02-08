#include <iostream>
#include <vector>
using namespace std;


class  agrupacionMusical{
protected:
    string nombre;
    int id;
    int cantidadDeIntegrantes;
public:
    agrupacionMusical(string nombre, int id, int cantidadDeIntegrantes  /*aca puede ir hacer una asociacion*/):nombre(nombre),id(id),cantidadDeIntegrantes(cantidadDeIntegrantes){}

    agrupacionMusical(){
        this->nombre = "";
        this->id = 0;
        this->cantidadDeIntegrantes = 0;
    }

    const string &getNombre() const {
        return nombre;
    }

    void setNombre(const string &nombre) {
        agrupacionMusical::nombre = nombre;
    }

    int getId() const {
        return id;
    }

    void setId(int id) {
        agrupacionMusical::id = id;
    }

    int getCantidadDeIntegrantes() const {
        return cantidadDeIntegrantes;
    }

    void setCantidadDeIntegrantes(int cantidadDeIntegrantes) {
        agrupacionMusical::cantidadDeIntegrantes = cantidadDeIntegrantes;
    }

    virtual void tocar(){
        cout<< "Upss, no sabemos donde esta la agrupacion!!"<<endl;
    }
    void print(){
        cout<< "Nombre: "<<nombre<<endl;
        cout<< "Id: "<<id<<endl;
        cout<< "Cantidad de integrantes: "<<cantidadDeIntegrantes<<endl;
    }

    friend ostream &operator<<(ostream &output, agrupacionMusical &m1){
        output<<"Nombre: "<<m1.nombre<<endl;
        output<<"Id: "<< m1.id<<endl;
        output<<"Cantidad de integranges: "<<m1.cantidadDeIntegrantes<<endl;
        return output;
    }


};

class banda:public agrupacionMusical{
protected:
    string genero;
    
public:
    banda(string nombre, int id, int cantidadDeIntegrantes,string genero):agrupacionMusical(nombre,id,cantidadDeIntegrantes),genero(genero){}
    banda(){
        this->nombre="";
        this->id=0;
        this->cantidadDeIntegrantes = 0;
        this->genero="";
    }

    void tocar()override{
        cout<< "tumpa tumpa tumpa tumpa"<<endl;
    }

    const string &getGenero() const {
        return genero;
    }

    void setGenero(const string &genero) {
        banda::genero = genero;
    }
    
    void print(){
        agrupacionMusical::print();
        cout<< "Genero: "<<genero<<endl;
    }
    friend ostream &operator<<(ostream &output, banda &b1){
        b1.agrupacionMusical::print();
        output<<"Genero: "<<b1.genero<<endl;
    }
};

class orquesta:public agrupacionMusical{
protected:
    string TipoOrquesta;

public:
    orquesta(string nombre, int id, int cantidadDeIntegrantes, string tipoOrquesta):agrupacionMusical(nombre,id,cantidadDeIntegrantes),TipoOrquesta(tipoOrquesta){}

    orquesta(){
        this->nombre = "";
        this->id = 0;
        this->cantidadDeIntegrantes = 0;
        this->TipoOrquesta = "";
    }

    const string &getTipoOrquesta() const {
        return TipoOrquesta;
    }

    void setTipoOrquesta(const string &tipoOrquesta) {
        TipoOrquesta = tipoOrquesta;
    }

    void tocar() override{
        cout<<"el director de orquesta esta iniciando la obra"<<endl;
    }
    void print(){
        agrupacionMusical::print();
        cout<< "Tipo de orquesta: "<<TipoOrquesta<<endl;
    }
    friend ostream &operator<<(ostream &output, orquesta o1){
        o1.agrupacionMusical::print();
        output<<"Tipo de orquesta: "<<o1.TipoOrquesta<<endl;
        return output;
    }



};


// Definimos las interfaces
class Musica
{
public:
    virtual bool Tocar() = 0;
};//yo quitaria musica

class ArtistaNacional
{

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

class Boletos
{
protected:
    int idBoleto;
    string FechaValidez;

public:
    Boletos()
    {
        idBoleto = 0;
        FechaValidez = "";
    }
    Boletos(int idBoleto, string FechaValidez) : idBoleto(idBoleto), FechaValidez(FechaValidez)
    {
    }
    // Definimos el metodo virtualmente puro
    virtual string Manilla() = 0;

    // Hacemos la encapsulacion
    int getidBoleto()
    {
        return idBoleto;
    }

    void setidBoleto(int idBoleto)
    {
        this->idBoleto = idBoleto;
    }
    string getFechaValidez()
    {
        return FechaValidez;
    }

    void setFechaValidez(string FechaValidez)
    {
        this->FechaValidez = FechaValidez;
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

class Banda : public Persona, public Musica
{
protected:
    int cantidadIntegrantes;

public:
    Banda() : Persona()
    {
        cantidadIntegrantes = 0;
    }
    Banda(int id, string nombre, int edad, int cantidadIntegrantes) : Persona(id, nombre, edad), cantidadIntegrantes(cantidadIntegrantes)
    {
    }

    int getcantidadIntegrantes()
    {
        return cantidadIntegrantes;
    }

    void setcantidadIntegrantes(int cantidadIntegrantes)
    {
        this->cantidadIntegrantes = cantidadIntegrantes;
    }

    friend ostream &operator<<(ostream &output, Banda &p)
    {
        p.Persona::print();
        output << "Cantidad de integrantes " << p.getcantidadIntegrantes() << endl;
        return output;
    }

    int Salario() override
    {
        return 1;
    }
    bool Tocar() override
    {
        return false;
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
    string ciudad;

public:
    Dj() : Artista()
    {
        ciudad = "";
    }
    Dj(int id, string nombre, int edad, int AñosExperiencia, string apodo, string ciudad) : Artista(id, nombre, edad, AñosExperiencia, apodo), ciudad(ciudad)
    {
    }

    string getCiudad()
    {
        return ciudad;
    }

    void setCiudad(int ciudad)
    {
        this->ciudad = ciudad;
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
};
class BoletoNormal : public Boletos
{
protected:
    int valor;

public:
    BoletoNormal() : Boletos()
    {
        valor = 0;
    }
    BoletoNormal(int idBoletos, string FechaValidez, int valor) : Boletos(idBoletos, FechaValidez), valor(valor)
    {
    }

    int getValor()
    {
        return valor;
    }

    void setValor(int valor)
    {
        this->valor = valor;
    }
    void print()
    {
        Boletos::print();
        cout << "el valor del boleto de media es : " << getValor() << endl;
    }
    friend ostream &operator<<(ostream &output, BoletoNormal &p)
    {
        p.Boletos::print();

        output << "el valor del boleto de media es : " << p.getValor() << endl;
        return output;
    }

    string Manilla()
    {
        return "manilla roja";
    }
};
class BoletoVip : public Boletos
{
protected:
    int valor;

public:
    BoletoVip() : Boletos()
    {
        valor = 0;
    }
    BoletoVip(int idBoletos, string FechaValidez, int valor) : Boletos(idBoletos, FechaValidez), valor(valor)
    {
    }

    int getValor()
    {
        return valor;
    }

    void setValor(int valor)
    {
        this->valor = valor;
    }
    void print()
    {
        Boletos::print();
        cout << "el valor del boleto de media es : " << getValor() << endl;
    }
    friend ostream &operator<<(ostream &output, BoletoVip &p)
    {
        p.Boletos::print();

        output << "el valor del boleto de media es : " << p.getValor() << endl;
        return output;
    }

    string Manilla()
    {
        return "manilla roja";
    }
};
class BoletoMedia : public Boletos
{
protected:
    int valor;

public:
    BoletoMedia() : Boletos()
    {
        valor = 0;
    }
    BoletoMedia(int idBoletos, string FechaValidez, int valor) : Boletos(idBoletos, FechaValidez), valor(valor)
    {
    }

    int getValor()
    {
        return valor;
    }

    void setValor(int valor)
    {
        this->valor = valor;
    }
    void print()
    {
        Boletos::print();
        cout << "el valor del boleto de media es : " << getValor() << endl;
    }
    friend ostream &operator<<(ostream &output, BoletoMedia &p)
    {
        p.Boletos::print();

        output << "el valor del boleto de media es : " << p.getValor() << endl;
        return output;
    }

    string Manilla()
    {
        return "manilla roja";
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

    string getFrase()
    {
        return "cocacola";
    }

    virtual string consumo(){
        string cons = "";
        return cons;
    }
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

    void print() {
        producto::print();
        cout<< "caloritas: "<<getCalorias();
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
class Patrocinador : public Persona
{
protected:
    string Empresa;

public:
    Patrocinador() : Persona()
    {
        Empresa = "";
    }
    Patrocinador(int id, string nombre, int edad, string Empresa) : Persona(id, nombre, edad), Empresa(Empresa)
    {
    }

    string getEmpresa()
    {
        return Empresa;
    }

    void setEmpresa(string Empresa)
    {
        this->Empresa = Empresa;
    }

    int Salario() override
    {
        return 0;
    }
    void print() override
    {
        Persona::print();

        cout << "Empresa: " << getEmpresa() << endl;
    }
    friend ostream &operator<<(ostream &output, Patrocinador &p)
    {
        p.Persona::print();

        output << "Empresa: " << p.getEmpresa() << endl;
        return output;
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

/*class seguridad{
public:
    virtual string usoDeArmas()=0;
};
class vigilante:public seguridad, Persona{
protected:
    //cualquier atributo no se que poner la vd xd
public:
    vigilante(string nombre, int id, int edad):persona(nombre,id, edad);
    string usoDeArmas() override{
        string usoDeArmas = "bolillo";
        cout<< usoDeArmas;
        return usoDeArmas;
    }
};
class policia:public Persona,seguridad{
protected:
    string Rango;
public:
    string usoDeArmas() override{
        string usoDeArma = "Pistola y revolver";
        cout<<usoDeArma;
        return usoDeArma;
    }
    policia(string nombre, int id, int edad, string Rango):Persona(id,nombre,edad),Rango(Rango){};
};*/

class FuerzaPolicial : public Persona, public Movilizacion
{
protected:
    string Rango;
    string Cuadrante;

public:
    FuerzaPolicial() : Persona()
    {
        Rango = "";
        Cuadrante = "";
    }
    FuerzaPolicial(int id, string nombre, int edad, string Rango, string Cuadrante) : Persona(id, nombre, edad), Rango(Rango), Cuadrante(Cuadrante)
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

    int Salario() override
    {
        return 0;
    }
    void print() override
    {
        Persona::print();
        cout << "Rango es" << getRango() << endl;
        cout << "el cuadrante es: " << getCuadrante() << endl;
    }
    friend ostream &operator<<(ostream &output, FuerzaPolicial &p)
    {
        p.Persona::print();
        output << "Rango es " << p.getRango() << endl;
        output << "el cuadrante es:: " << p.getCuadrante() << endl;
        return output;
    }

    string TipoVehiculo() override
    {
        return "moto";
    }
};
class Evento : public Lugar, public Ubicacion, public Efectos
{
protected:
    string Titulo;
    int TiendasDisponibles;

public:
    Evento() : Lugar(), Ubicacion()
    {
        Titulo = "";
        TiendasDisponibles = 0;
    }
    Evento(string NombreLugar, double CapacidadMinima, double CapacidadMaxima, string Direccion, string Ciudad, string Titulo, int TiendasDisponibles) : Lugar(NombreLugar, CapacidadMinima, CapacidadMaxima), Ubicacion(Direccion, ciudad), Titulo(Titulo), TiendasDisponibles(TiendasDisponibles)
    {
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

    void print()
    {
        Lugar::print();
        Ubicacion::print();
        cout << "Nombre del Evento: " << getTitulo() << endl;
        cout << "Cantidad de tiendas en evento: " << getTiendasDisponiblesTitulo() << endl;
    }
    friend ostream &operator<<(ostream &output, Evento &p)
    {
        p.Lugar::print();
        p.Ubicacion::print();
        output << "Nombre del Evento: " << p.getTitulo() << endl;
        output << "Cantidad de tiendas en evento: " << p.getTiendasDisponiblesTitulo() << endl;
        return output;
    }
    string Example()
    {
        return "jeje";
    }

    string gps()
    {
        return "flex";
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
        return "";
    }
};
class VendedorEntradas : public Empleado
{
protected:
public:
};
class Espectador : public Persona
{

public:
};

int main()
{
    // FuerzaPolicial a(45, "jajaja", 45, "cadete", "catama");
    // cout << a;
    // Marketing b(45, "jajaja", 45,4);
    // cout << b;
    // Patrocinador c(45, "jajaja", 45,"sasoftco");
    // cout << c;

    // Evento *a = new Evento("el j", 15, 54, "c", "villa", "j", 45);
    // cout << a;

    Logistica a(12, "juan", 45, 452, "dddd", "ddfgfdf", "ffvffvv");
    //cout << a;

    agrupacionMusical *a1 = new banda("angelito69",1010,1,"xd??");
    //a1->tocar();

    a1 = new orquesta("xd",2020,3,"sifonica");
    //a1->tocar();

    comida comida1 = comida("papitas",20320,"Margarita",200);
    //comida1.print();

    agrupacionMusical ag1 = agrupacionMusical("La Mejor de todas",2020,3);
    banda losRecoditos = banda("los Recoditos de Monterrey", 21,5,"banda");
    cout<< ag1;
    cout<< losRecoditos;
    
}