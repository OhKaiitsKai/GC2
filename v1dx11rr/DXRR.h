#ifndef _dxrr
#define _dxrr
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dx10.h>
#include "Diosito.h"
#include <d3dx10math.h>
#include "TerrenoRR.h"
#include "Camara.h"
#include "SkyDome.h"
#include "Billboard.h"
#include "ModeloRR.h"
#include "Water.h"
#include "XACT3Util.h"
#include <math.h>
#include <string>
#include "GUI.h"
#include "Imagen.h"
#include "Text.h"
#include "Agua.h"

Diosito* dio;
Imagen* ima = new Imagen();
ModeloRR* xddd = new ModeloRR;
bool status = false;
bool status2 = false;

#define PI 3.14159265
class DXRR {

private:
	int ancho;
	int alto;
public:

	//AGUA
	Agua* Awa;

	//Texto
	Text* tiempo;
	float segundos;
	bool status2 = false;

	//SKYDOM
	int Contador;
	int ContFramesTarde;
	int ContFramesNoche;
	int ContFramesMañana;
	int contadorGLSL;
	float DifAmb[2];
	float luzAmb[4];
	float posY, posX, posZ;
	float PosicionesLuzDinamic[3];
	float fad;
	float fa;
	float fas;	
	float angle;
	float luzx = 0.0f;
	float luzy = 0.0f;
	float luzz = 0.0f;

	//GUI
	GUI* nota_1_imagen;
	GUI* nota_2_imagen;
	GUI* nota_3_imagen;
	GUI* nota_4_imagen;
	GUI* nota_5_imagen;
	GUI* nota_6_imagen;
	GUI* nota_7_imagen;
	GUI* nota_8_imagen;
	GUI* nota_9_imagen;
	GUI* nota_10_imagen;
	GUI* Nota_Ganar;
	GUI* Nota_Perder;
	GUI* Nota_Incorrecta;

	HINSTANCE hInstance;
	HWND hWnd;
	bool validador1 = false;
	bool ganar = false;
	D3D_DRIVER_TYPE driverType;
	D3D_FEATURE_LEVEL featureLevel;

	ID3D11Device* d3dDevice;
	ID3D11DeviceContext* d3dContext;
	IDXGISwapChain* swapChain;
	ID3D11RenderTargetView* backBufferTarget;

	ID3D11Texture2D* depthTexture;
	ID3D11DepthStencilView* depthStencilView;

	ID3D11DepthStencilState* depthStencilState;
	ID3D11DepthStencilState* depthStencilDisabledState;

	ID3D11BlendState* alphaBlendState, * commonBlendState;
	D3DXVECTOR3 dirluz;

	float m_waterTranslation;

	int frameBillboard;
	D3DXVECTOR4 luzAmbiental;
	D3DXVECTOR4 luzDifusa;
	D3DXVECTOR4 luzEspecular;
	TerrenoRR* terreno;
	SkyDome* skydome;
	BillboardRR* billboard;
	BillboardRR* arbol;
	BillboardRR* arbusto;
	BillboardRR* arbol2;
	Camara* camara;
	ModeloRR* model;
	ModeloRR* coche;
	ModeloRR* atril;
	ModeloRR* banca;
	ModeloRR* boteBasura;
	ModeloRR* caballete;
	ModeloRR* lampara;
	ModeloRR* mesaPicnic;
	ModeloRR* Car;
	ModeloRR* museo;
	ModeloRR* puesto;
	ModeloRR* computadora;
	ModeloRR* escurridor;
	ModeloRR* estanterias;
	ModeloRR* exhibidor;
	ModeloRR* lamparas;
	ModeloRR* lavabo;
	ModeloRR* licuadoras;
	ModeloRR* muebles;
	ModeloRR* platosEscurridor;
	ModeloRR* platosTazas;
	ModeloRR* puerta;
	ModeloRR* utensilios1;
	ModeloRR* utensilios3;
	ModeloRR* Fruta1;
	ModeloRR* Fruta2;
	ModeloRR* Fruta3;
	ModeloRR* Fruta4;
	ModeloRR* Fruta5;
	ModeloRR* Fruta6;
	ModeloRR* Fruta7;
	ModeloRR* Fruta8;
	ModeloRR* Fruta9;
	ModeloRR* Fruta10;
	ModeloRR* cuadro1;
	ModeloRR* cuadro2;
	ModeloRR* cuadro3;
	ModeloRR* cuadro4;
	ModeloRR* cuadro5;
	ModeloRR* cuadro6;
	ModeloRR* cuadro7;
	ModeloRR* cuadro8;
	ModeloRR* cuadro9;
	ModeloRR* cuadro10;
	ModeloRR* venus;
	ModeloRR* zeus;
	ModeloRR* discolombus;
		
	Water* aguadenise;
		
	D3DXVECTOR3 camaraxd;

	D3DXVECTOR3 pos;

	float izqder;
	float arriaba;
	float vel;
	bool breakpoint;

	float angy = 0;
	float angx = 0;

	vector2 uv1[32];
	vector2 uv2[32];
	vector2 uv3[32];
	vector2 uv4[32];

	XACTINDEX cueIndex;																														//MUSIC
	CXACT3Util m_XACT3;

	float rotCam;
	int tipoCam;

	bool coords;

	bool effectDone;

	DXRR(HWND hWnd, int Ancho, int Alto)
	{
		//SkyDom
		ContFramesMañana = 80;
		ContFramesNoche = 40;
		ContFramesTarde = 80;
		contadorGLSL = 0;
		fad = 0.4f;
		fa = 0.8f;
		fas = 3.0f;
		angle = 0.0f;
		float luzx = 0.0f;
		float luzy = 0.0f;
		float luzz = 0.0f;

		
		
		



																																																			 //CONTADOR


		segundos = 480;																																										 //8 minutos
		//segundos = 420;																																										 //7 minutos
		//segundos = 360;																																										 //6 minutos
		//segundos = 300;																																										 //5 minutos
		//segundos = 180;																																										 //3 minutos
		//segundos = 30;








		effectDone = false;
		coords = false;
		rotCam = 0;
		tipoCam = 1;
		luzAmbiental = D3DXVECTOR4(0.0f, 0.0f, 0.0f, 0.0f);
		luzDifusa = D3DXVECTOR4(0.0f, 0.0f, 0.0f, 0.0f);
		luzEspecular = D3DXVECTOR4(0.0f, 0.0f, 0.0f, 0.0f);
		m_waterTranslation = 0;

		breakpoint = false;
		frameBillboard = 0;
		ancho = Ancho;
		alto = Alto;
		driverType = D3D_DRIVER_TYPE_NULL;
		featureLevel = D3D_FEATURE_LEVEL_11_0;
		d3dDevice = 0;
		d3dContext = 0;
		swapChain = 0;
		backBufferTarget = 0;
		IniciaD3D(hWnd);
		izqder = 0;
		arriaba = 0;
		billCargaFuego();

		camara = new Camara(D3DXVECTOR3(0, 100, 6), D3DXVECTOR3(0, 80, 0), D3DXVECTOR3(0, 1, 0), Ancho, Alto);

		terreno = new TerrenoRR(L"Dirt3.jpg", L"Dirt3_spec.png", L"Dirt3_norm.png",
			L"path.png", L"path_spec.png", L"path_norm.png",
			L"Grass_8.jpg", L"Grass_7_spec.png", L"Grass_7_norm.png",
			L"hm2.png", 300, 300, d3dDevice, d3dContext);


		dio = new Diosito(*camara);


		//skydome = new SkyDome(32, 32, 100.0f, &d3dDevice, &d3dContext, L"SkyDome2.png");
		
		
		skydome = new SkyDome(32, 32, 100.0f, &d3dDevice, &d3dContext, L"SkyDomeDaylight.jpg", L"SkyDomeTwillight.jpg", L"SkyDomeNight.jpg");


		billboard = new BillboardRR(L"Assets/Billboards/fuego-anim.png", L"Assets/Billboards/fuego-anim-normal.png", d3dDevice, d3dContext, 5);
		arbol = new BillboardRR(L"Assets/Billboards/Arbolito1.png", L"Assets/Billboards/Arbolito1.png", d3dDevice, d3dContext, 5);
		arbol2 = new BillboardRR(L"Assets/Billboards/Arbolito2.png", L"Assets/Billboards/Arbolito2.png", d3dDevice, d3dContext, 5);
		arbusto = new BillboardRR(L"Assets/Billboards/Arbusto.png", L"Assets/Billboards/Arbusto.png", d3dDevice, d3dContext, 5);

		//coche = new ModeloRR(d3dDevice, d3dContext, "Assets/Coche/sportCar12.obj", L"Assets/Coche/sportCar12.png", L"Assets/Coche/sportCar12_norm.png", -60, 0);
		atril = new ModeloRR(d3dDevice, d3dContext, "Assets/Atril/Atril.obj", L"Assets/Atril/Atril.png", L"Assets/Atril/Atril_spec.png", L"Assets/Agua/norm.jpg", -60, 10);
		banca = new ModeloRR(d3dDevice, d3dContext, "Assets/Banca/Banca1.obj", L"Assets/Banca/Banca_base_color1.png", L"Assets/Banca/Banca_spec1.png", L"Assets/Agua/norm.jpg", -60, 20);
		boteBasura = new ModeloRR(d3dDevice, d3dContext, "Assets/BoteBasura/Street_bin_recycle.obj", L"Assets/BoteBasura/Blue_BaseColor.png", L"Assets/BoteBasura/SpecularMap.png", L"Assets/Agua/norm.jpg", -60, 30);
		caballete = new ModeloRR(d3dDevice, d3dContext, "Assets/Caballete/Caballete.obj", L"Assets/Caballete/wood_texture.png", L"Assets/Caballete/wood_spec.png", L"Assets/Agua/norm.jpg", -60, -10);
		lampara = new ModeloRR(d3dDevice, d3dContext, "Assets/Lampara/Lampara.obj", L"Assets/Lampara/Lampara_base_color.png", L"Assets/Lampara/Lampara_base_spec.png", L"Assets/Agua/norm.jpg", -25, -15);
		mesaPicnic = new ModeloRR(d3dDevice, d3dContext, "Assets/MesaPicnic/mesaPicnic1.obj", L"Assets/MesaPicnic/mesa_de_picnic1.png", L"Assets/MesaPicnic/mesa_de_picnic_spec1.png", L"Assets/Agua/norm.jpg", 80, -80);
		Car = new ModeloRR(d3dDevice, d3dContext, "Assets/Car/Car.obj", L"Assets/Car/Car.png", L"Assets/Car/Car-in.png", L"Assets/Car/Car - copia.png", 0, 0);
		museo = new ModeloRR(d3dDevice, d3dContext, "Assets/WoodHouse/WoodHouse.obj", L"Assets/WoodHouse/Diffuse.png", L"Assets/WoodHouse/Diffuse.png", L"Assets/WoodHouse/normal.png", -0, 110);
		puesto = new ModeloRR(d3dDevice, d3dContext, "Assets/Puesto/Puesto2.obj", L"Assets/Puesto/Puesto2.png", L"Assets/Puesto/Puesto2.png", L"Assets/Agua/norm.jpg", 100, -90);
		computadora = new ModeloRR(d3dDevice, d3dContext, "Assets/Puesto/Computadora.obj", L"Assets/Puesto/Computadora.png", L"Assets/Puesto/Computadora.png", L"Assets/Agua/norm.jpg", 100, -90);
		escurridor = new ModeloRR(d3dDevice, d3dContext, "Assets/Puesto/Escurridor.obj", L"Assets/Puesto/Escurridor.png", L"Assets/Puesto/Escurridor.png", L"Assets/Agua/norm.jpg", 100, -90);
		estanterias = new ModeloRR(d3dDevice, d3dContext, "Assets/Puesto/Estanterias.obj", L"Assets/Puesto/Estanterias.png", L"Assets/Puesto/Estanterias.png", L"Assets/Agua/norm.jpg", 100, -90);
		exhibidor = new ModeloRR(d3dDevice, d3dContext, "Assets/Puesto/Exhibidor.obj", L"Assets/Puesto/Exhibidor.png", L"Assets/Puesto/Exhibidor.png", L"Assets/Agua/norm.jpg", 100, -90);
		lamparas = new ModeloRR(d3dDevice, d3dContext, "Assets/Puesto/Lamparas.obj", L"Assets/Puesto/Lamparas.png", L"Assets/Puesto/Lamparas.png", L"Assets/Agua/norm.jpg", 100, -90);
		lavabo = new ModeloRR(d3dDevice, d3dContext, "Assets/Puesto/Lavabo.obj", L"Assets/Puesto/Lavabo.png", L"Assets/Puesto/Lavabo.png", L"Assets/Agua/norm.jpg", 100, -90);
		licuadoras = new ModeloRR(d3dDevice, d3dContext, "Assets/Puesto/Licuadoras.obj", L"Assets/Puesto/Licuadora.png", L"Assets/Puesto/Licuadora.png", L"Assets/Agua/norm.jpg", 100, -90);
		muebles = new ModeloRR(d3dDevice, d3dContext, "Assets/Puesto/Muebles.obj", L"Assets/Puesto/Muebles.png", L"Assets/Puesto/Muebles.png", L"Assets/Agua/norm.jpg", 100, -90);
		platosEscurridor = new ModeloRR(d3dDevice, d3dContext, "Assets/Puesto/Platos escurridor.obj", L"Assets/Puesto/Platos escurridor.png", L"Assets/Puesto/Platos escurridor.png", L"Assets/Agua/norm.jpg", 100, -90);
		platosTazas = new ModeloRR(d3dDevice, d3dContext, "Assets/Puesto/Platos y tazas.obj", L"Assets/Puesto/Platos y tazas.png", L"Assets/Puesto/Platos y tazas.png", L"Assets/Agua/norm.jpg", 100, -90);
		puerta = new ModeloRR(d3dDevice, d3dContext, "Assets/Puesto/Puerta.obj", L"Assets/Puesto/Puerta.png", L"Assets/Puesto/Puerta.png", L"Assets/Agua/norm.jpg", 100, -90);
		utensilios1 = new ModeloRR(d3dDevice, d3dContext, "Assets/Puesto/Utensilios1.obj", L"Assets/Puesto/Utensilios1.png", L"Assets/Puesto/Utensilios1.png", L"Assets/Agua/norm.jpg", 100, -90);
		utensilios3 = new ModeloRR(d3dDevice, d3dContext, "Assets/Puesto/Utensilios3.obj", L"Assets/Puesto/Utensilios3.png", L"Assets/Puesto/Utensilios3.png", L"Assets/Agua/norm.jpg", 100, -90);

		// FRUTAS (MODELOS) 
		Fruta1 = new ModeloRR(d3dDevice, d3dContext, "Assets/Carrot/Carrot.obj", L"Assets/Carrot/Carrot.png", L"Assets/Carrot/Carrot-i.png", L"Assets/Carrot/Carrot-b.png", -70, 70); //Zanahoria
		Fruta2 = new ModeloRR(d3dDevice, d3dContext, "Assets/sandia/Watermelon.obj", L"Assets/sandia/Watermelon.png", L"Assets/sandia/Watermelon-i.png", L"Assets/sandia/Watermelon-b.png", 70, -70); //Sandía
		Fruta3 = new ModeloRR(d3dDevice, d3dContext, "Assets/Apple/Apple00.obj", L"Assets/Apple/apple00_alb.png", L"Assets/Apple/apple00-i.png", L"Assets/Apple/Apple00-b.png", -70, -70); //Manzana
		Fruta4 = new ModeloRR(d3dDevice, d3dContext, "Assets/Banana/Banana.obj", L"Assets/Banana/Banana.png", L"Assets/Banana/Banana-i.png", L"Assets/Banana/Banana-b.png", 70, 70); //Plátano
		Fruta5 = new ModeloRR(d3dDevice, d3dContext, "Assets/Bellpepper/Bellpepper.obj", L"Assets/Bellpepper/Bellpepper.png", L"Assets/Bellpepper/Bellpepper.png", L"Assets/Bellpepper/Bellpepper.png", -50, 100); //Chile
		Fruta6 = new ModeloRR(d3dDevice, d3dContext, "Assets/Broccoli/Brocolli.obj", L"Assets/Broccoli/Broccoli.png", L"Assets/Broccoli/Broccoli-i.png", L"Assets/Broccoli/Broccoli-b.png", 50, -100); //Broccoli
		Fruta7 = new ModeloRR(d3dDevice, d3dContext, "Assets/Orange/Orange.obj", L"Assets/Orange/Orange.png", L"Assets/Orange/Orange-i.png", L"Assets/Orange/Orange-b.png", 50, 100); //Naranja
		Fruta8 = new ModeloRR(d3dDevice, d3dContext, "Assets/Apple-green/Apple.obj", L"Assets/Apple-green/Apple.png", L"Assets/Apple-green/Apple-i.png", L"Assets/Apple-green/Apple-b.png", -50, -100); //Manzana verde
		Fruta9 = new ModeloRR(d3dDevice, d3dContext, "Assets/Strawberry/Strawberry.obj", L"Assets/Strawberry/Strawberry.png", L"Assets/Strawberry/Strawberry-i.png", L"Assets/Strawberry/Strawberry-b.png", 20,  20); //Fresa
		Fruta10 = new ModeloRR(d3dDevice, d3dContext, "Assets/elote/Mais.obj", L"Assets/elote/Mais.png", L"Assets/elote/Mais-i.png", L"Assets/elote/Mais-b.png", -20,  -20); //Elote

		// IMAGENES
		nota_1_imagen = new GUI(d3dDevice, d3dContext, 0.05, 0.06, L"Assets/Notas/zanahoria.png"); //zanahoria
		nota_2_imagen = new GUI(d3dDevice, d3dContext, 0.05, 0.06, L"Assets/Notas/sandia.png"); //Sandía
		nota_3_imagen = new GUI(d3dDevice, d3dContext, 0.05, 0.06, L"Assets/Notas/manzanaNota.png"); //Manzana
		nota_4_imagen = new GUI(d3dDevice, d3dContext, 0.05, 0.06, L"Assets/Notas/platano.png"); //Plátano
		nota_5_imagen = new GUI(d3dDevice, d3dContext, 0.05, 0.06, L"Assets/Notas/chile.png"); //Chile
		nota_6_imagen = new GUI(d3dDevice, d3dContext, 0.05, 0.06, L"Assets/Notas/broccoli.png"); //Broccoli
		nota_7_imagen = new GUI(d3dDevice, d3dContext, 0.05, 0.06, L"Assets/Notas/naranja.png"); //Naranja
		nota_8_imagen = new GUI(d3dDevice, d3dContext, 0.05, 0.06, L"Assets/Notas/manzanaVerde.png"); //Manzana verde
		nota_9_imagen = new GUI(d3dDevice, d3dContext, 0.05, 0.06, L"Assets/Notas/fresa.png"); //Fresa
		nota_10_imagen = new GUI(d3dDevice, d3dContext, 0.05, 0.06, L"Assets/Notas/elote.png"); //Elote
		Nota_Ganar = new GUI(d3dDevice, d3dContext, 0.05, 0.06, L"Assets/Notas/Win1.png"); //Nota Ganar
		Nota_Perder = new GUI(d3dDevice, d3dContext, 0.05, 0.06, L"Assets/Notas/Lose1.png"); //Nota Perder
		Nota_Incorrecta = new GUI(d3dDevice, d3dContext, 0.08, 0.08, L"Assets/Notas/notaFallaste.png"); //Nota Incorrecta

		//CUADROS
		cuadro1 = new ModeloRR(d3dDevice, d3dContext, "Assets/Cuadro1/cuadro.obj", L"Assets/Cuadro1/zanahoria.jpg", L"Assets/Cuadro1/zanahoria.jpg", L"Assets/Cuadro1/zanahoria.jpg", 3.1, 78.3);// Noche Estrellada
		cuadro10 = new ModeloRR(d3dDevice, d3dContext, "Assets/Cuadro1/cuadro2.obj", L"Assets/Cuadro1/sandia.jpg", L"Assets/Cuadro1/sandia.jpg", L"Assets/Cuadro1/sandia.jpg", 49.5, 78.3); //La Monalisa
		cuadro6 = new ModeloRR(d3dDevice, d3dContext, "Assets/Cuadro1/cuadro2.obj", L"Assets/Cuadro1/manzana.jpg", L"Assets/Cuadro1/manzana.jpg", L"Assets/Cuadro1/manzana.jpg", 26.5, 78.3); //El beso
		cuadro9 = new ModeloRR(d3dDevice, d3dContext, "Assets/Cuadro1/cuadro2.obj", L"Assets/Cuadro1/platano.jpg", L"Assets/Cuadro1/platano.jpg", L"Assets/Cuadro1/platano.jpg", 43.5, 78.3); //La Joven de Perla
		cuadro5 = new ModeloRR(d3dDevice, d3dContext, "Assets/Cuadro1/cuadro.obj", L"Assets/Cuadro1/chile.jpg", L"Assets/Cuadro1/chile.jpg", L"Assets/Cuadro1/chile.jpg", 21.5, 78.3);//El Nacimiento de Venus
		cuadro8 = new ModeloRR(d3dDevice, d3dContext, "Assets/Cuadro1/cuadro2.obj", L"Assets/Cuadro1/broccoli.jpg", L"Assets/Cuadro1/broccoli.jpg", L"Assets/Cuadro1/broccoli.jpg", 37.5, 78.3);//El Hijo del Hombre
		cuadro7 = new ModeloRR(d3dDevice, d3dContext, "Assets/Cuadro1/cuadro2.obj", L"Assets/Cuadro1/naranja.jpg", L"Assets/Cuadro1/naranja.jpg", L"Assets/Cuadro1/naranja.jpg", 32.5, 78.3);//El grito
		cuadro4 = new ModeloRR(d3dDevice, d3dContext, "Assets/Cuadro1/cuadro.obj", L"Assets/Cuadro1/manzanaverde.jpg", L"Assets/Cuadro1/manzanaverde.jpg", L"Assets/Cuadro1/manzanaverde.jpg", 15.5, 78.3);//Las 2 Fridas
		cuadro3 = new ModeloRR(d3dDevice, d3dContext, "Assets/Cuadro1/cuadro.obj", L"Assets/Cuadro1/fresa.jpg", L"Assets/Cuadro1/fresa.jpg", L"Assets/Cuadro1/fresa.jpg", -3.5, 78.3);//La Creacion de Adam
		cuadro2 = new ModeloRR(d3dDevice, d3dContext, "Assets/Cuadro1/cuadro.obj", L"Assets/Cuadro1/elote.jpg", L"Assets/Cuadro1/elote.jpg", L"Assets/Cuadro1/elote.jpg", 9.5, 78.3);//Guernica
	
		//Estatuas
		venus = new ModeloRR(d3dDevice, d3dContext, "Assets/Venus/venus_de_milo_LP.obj", L"Assets/Venus/estatua.jpg", L"Assets/Venus/color.png", L"Assets/Venus/normal.png", 10, 10);//Guernica
		discolombus = new ModeloRR(d3dDevice, d3dContext, "Assets/Discolombus/Discolombus.obj", L"Assets/Discolombus/estatua.jpg", L"Assets/Venus/color.png", L"Assets/Discolombus/normal.png", -97, -72);//Guernica
		zeus = new ModeloRR(d3dDevice, d3dContext, "Assets/Zeus/Zeus.obj", L"Assets/Zeus/estatua.jpg", L"Assets/Venus/color.png", L"Assets/Zeus/normal.png", 38, -114);//Guernica


		//Texto
		tiempo = new Text(d3dDevice, d3dContext, 3.6, 1.2, L"Assets/GUI/font.jpg", XMFLOAT4(0.39f, 0.79f, 0.18f, 1.0f));

		//AWA
		Awa = new Agua(d3dDevice, d3dContext, "Assets/Agua/agua.obj", L"Assets/Awa/aguatext.png", L"Assets/Awa/aguaespec.png", 112, 50);
		
		aguadenise = new Water(d3dDevice, d3dContext, "Assets/Agua/agua.obj", L"Assets/Agua/aguaSpec.png", L"Assets/Agua/normal.jpg");
	}

	~DXRR()
	{
		LiberaD3D();
		m_XACT3.Terminate();
	}

	bool IniciaD3D(HWND hWnd)
	{
		this->hInstance = hInstance;
		this->hWnd = hWnd;

		//obtiene el ancho y alto de la ventana donde se dibuja
		RECT dimensions;
		GetClientRect(hWnd, &dimensions);
		unsigned int width = dimensions.right - dimensions.left;
		unsigned int heigth = dimensions.bottom - dimensions.top;

		//Las formas en como la pc puede ejecutar el DX11, la mas rapida es D3D_DRIVER_TYPE_HARDWARE pero solo se puede usar cuando lo soporte el hardware
		//otra opcion es D3D_DRIVER_TYPE_WARP que emula el DX11 en los equipos que no lo soportan
		//la opcion menos recomendada es D3D_DRIVER_TYPE_SOFTWARE, es la mas lenta y solo es util cuando se libera una version de DX que no sea soportada por hardware
		D3D_DRIVER_TYPE driverTypes[] =
		{
			D3D_DRIVER_TYPE_HARDWARE, D3D_DRIVER_TYPE_WARP, D3D_DRIVER_TYPE_SOFTWARE
		};
		unsigned int totalDriverTypes = ARRAYSIZE(driverTypes);

		//La version de DX que utilizara, en este caso el DX11
		D3D_FEATURE_LEVEL featureLevels[] =
		{
			D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_1, D3D_FEATURE_LEVEL_10_0
		};
		unsigned int totalFeaturesLevels = ARRAYSIZE(featureLevels);

		DXGI_SWAP_CHAIN_DESC swapChainDesc;
		ZeroMemory(&swapChainDesc, sizeof(swapChainDesc));
		swapChainDesc.BufferCount = 1;
		swapChainDesc.BufferDesc.Width = width;
		swapChainDesc.BufferDesc.Height = heigth;
		swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		swapChainDesc.BufferDesc.RefreshRate.Numerator = 60;
		swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
		swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		swapChainDesc.OutputWindow = hWnd;
		swapChainDesc.Windowed = true;
		swapChainDesc.SampleDesc.Count = 1;
		swapChainDesc.SampleDesc.Quality = 0;

		HRESULT result;
		unsigned int driver = 0, creationFlags = 0;
		for (driver = 0; driver < totalDriverTypes; driver++)
		{
			result = D3D11CreateDeviceAndSwapChain(0, driverTypes[driver], 0,
				creationFlags, featureLevels, totalFeaturesLevels,
				D3D11_SDK_VERSION, &swapChainDesc, &swapChain,
				&d3dDevice, &featureLevel, &d3dContext);

			if (SUCCEEDED(result))
			{
				driverType = driverTypes[driver];
				break;
			}
		}

		if (FAILED(result))
		{

			//Error al crear el Direct3D device
			return false;
		}

		ID3D11Texture2D* backBufferTexture;
		result = swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&backBufferTexture);
		if (FAILED(result))
		{
			//"Error al crear el swapChainBuffer
			return false;
		}

		result = d3dDevice->CreateRenderTargetView(backBufferTexture, 0, &backBufferTarget);
		if (backBufferTexture)
			backBufferTexture->Release();

		if (FAILED(result))
		{
			//Error al crear el renderTargetView
			return false;
		}


		D3D11_VIEWPORT viewport;
		viewport.Width = (FLOAT)width;
		viewport.Height = (FLOAT)heigth;
		viewport.MinDepth = 0.0f;
		viewport.MaxDepth = 1.0f;
		viewport.TopLeftX = 0.0f;
		viewport.TopLeftY = 0.0f;

		d3dContext->RSSetViewports(1, &viewport);

		D3D11_TEXTURE2D_DESC depthTexDesc;
		ZeroMemory(&depthTexDesc, sizeof(depthTexDesc));
		depthTexDesc.Width = width;
		depthTexDesc.Height = heigth;
		depthTexDesc.MipLevels = 1;
		depthTexDesc.ArraySize = 1;
		depthTexDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
		depthTexDesc.SampleDesc.Count = 1;
		depthTexDesc.SampleDesc.Quality = 0;
		depthTexDesc.Usage = D3D11_USAGE_DEFAULT;
		depthTexDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
		depthTexDesc.CPUAccessFlags = 0;
		depthTexDesc.MiscFlags = 0;

		result = d3dDevice->CreateTexture2D(&depthTexDesc, NULL, &depthTexture);
		if (FAILED(result))
		{
			MessageBox(0, L"Error", L"Error al crear la DepthTexture", MB_OK);
			return false;
		}

		D3D11_DEPTH_STENCIL_VIEW_DESC descDSV;
		ZeroMemory(&descDSV, sizeof(descDSV));
		descDSV.Format = depthTexDesc.Format;
		descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
		descDSV.Texture2D.MipSlice = 0;

		result = d3dDevice->CreateDepthStencilView(depthTexture, &descDSV, &depthStencilView);
		if (FAILED(result))
		{
			MessageBox(0, L"Error", L"Error al crear el depth stencil target view", MB_OK);
			return false;
		}

		d3dContext->OMSetRenderTargets(1, &backBufferTarget, depthStencilView);

		//Inicializar XACT
		bool res = m_XACT3.Initialize();
		if (!res) return false;
		res = m_XACT3.LoadWaveBank(L"Win\\WaveBank.xwb");
		if (!res)return false;
		res = m_XACT3.LoadSoundBank(L"Win\\SoundBank.xsb");
		if (!res)return false;

		//reproducir
		cueIndex = m_XACT3.m_pSoundBank->GetCueIndex("fondo");
		m_XACT3.m_pSoundBank->Play(cueIndex, 0, 0, 0);

		return true;
	}

	void LiberaD3D(void)
	{
		if (depthTexture)
			depthTexture->Release();
		if (depthStencilView)
			depthStencilView->Release();
		if (backBufferTarget)
			backBufferTarget->Release();
		if (swapChain)
			swapChain->Release();
		if (d3dContext)
			d3dContext->Release();
		if (d3dDevice)
			d3dDevice->Release();

		depthTexture = 0;
		depthStencilView = 0;
		d3dDevice = 0;
		d3dContext = 0;
		swapChain = 0;
		backBufferTarget = 0;
	}
	
	void Render(void)
	{
		static float Timer = 0;
		Timer += 0.0001;
		if (Timer > 1) {
			Timer = Timer - 1;
		}

		pintar();

		//Trabaja XACT
		m_XACT3.DoWork();																																																					//SONIDO

		//Texto

		m_waterTranslation += 0.01f;
		if (m_waterTranslation > 1.0f)
		{
			m_waterTranslation -= 1.0f;
		}

		if (coords) {
			char text[50];
			strcpy(text, "x: ");
			strcat(text, to_string(camara->posCam.x).c_str());
			strcat(text, " z: ");
			strcat(text, to_string(camara->posCam.z).c_str());

			MessageBox(0, L"Coords", (LPCWSTR)text, MB_OK);
			coords = false;
		}

		rotCam += izqder;

		float sphere[3] = { 0,0,0 };
		float prevPos[3] = { camara->posCam.x, camara->posCam.z, camara->posCam.z };
		float clearColor[4] = { 0, 0, 0, 1.0f };
		d3dContext->ClearRenderTargetView(backBufferTarget, clearColor);
		d3dContext->ClearDepthStencilView(depthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0);
		
		if (tipoCam == 1) {
			camara->posCam.y = terreno->Superficie(camara->posCam.x, camara->posCam.z) + 6.5;
		}
		else if (tipoCam == 3) {
			camara->posCam.y = terreno->Superficie(camara->posCam.x, camara->posCam.z) + 15;
		}
		
		//camara->posCam.y = terreno->Superficie(camara->posCam.x, camara->posCam.z) + 6.5;
		//camara->posCam3P.y = terreno->Superficie(camara->posCam3P.x, camara->posCam3P.z) + 15;
		camara->UpdateCam(vel, arriaba, izqder, tipoCam);
		skydome->Update(camara->vista, camara->proyeccion);

		char coords[50];
		strcpy(coords, to_string(camara->posCam.x).c_str());
		strcat(coords, ", ");
		strcat(coords, to_string(camara->posCam.z).c_str());

		SetWindowTextA(hWnd, coords);
		float camPosXZ[2] = { camara->posCam.x, camara->posCam.z };

		TurnOffDepth();
		//skydome->Render(camara->posCam);
		skydome->Render(camara->posCam, contadorGLSL);

		TurnOnDepth();

		terreno->Draw(camara->vista, camara->proyeccion, luzAmbiental, luzDifusa, luzEspecular, 10, 1, 0, dirluz);//ought to change



		Car->setPosX(camara->hdveo.x);
		Car->setPosZ(camara->hdveo.z);
		if (tipoCam == 1) {
			Car->Draw(camara->vista, camara->proyeccion, Car->getPosX(), 
				terreno->Superficie(camara->posCam.x, camara->posCam.z) - 0.5, Car->getPosZ(), 
				camara->posCam, 10.0f, rotCam, 'Y', 2, true, tipoCam);
		}
		else if (tipoCam == 3) {
			Car->Draw(camara->vista, camara->proyeccion, Car->getPosX(), 
				terreno->Superficie(camara->posCam3P.x, camara->posCam3P.z) - 0.5, Car->getPosZ(), 
				camara->posCam, 10.0f, rotCam, 'Y', 2, true, tipoCam);
		}
		


		tiempo->DrawText(-0.95, 0.95, "Tiempo Restante: " + tiempo->Time(segundos), 0.015);
		segundos -= 0.02;

		//AWA
		Awa->Draw(camara->vista, camara->proyeccion, terreno->Superficie(112, 50)+4, camara->posCam, 50.0f, 0, 'A', 1, Timer);
		//aguadenise->Draw(camara->vista, camara->proyeccion, 100, terreno->Superficie(100 + 2, 100 + 2), 100, camara->posCam, 50.0f, 0, 'A', 1, false, tipoCam, m_waterTranslation);


		if (camara->posCam.x < -130 || camara->posCam.x>130 || camara->posCam.z < -130 || camara->posCam.z>130) {
			camara->posCam = camara->posCamPast;
		}

		//NOTAS (Modelos)
		Fruta1->Draw(camara->vista, camara->proyeccion, Fruta1->getPosX(), terreno->Superficie(-34.9, -28.8), Fruta1->getPosZ(), camara->posCam, 200.0f, 44.8, 'Y', 8, false, tipoCam); //La noche estrella
		Fruta2->Draw(camara->vista, camara->proyeccion, Fruta2->getPosX(), terreno->Superficie(-34.9, -28.8), Fruta2->getPosZ(), camara->posCam, 200.0f, 44.8, 'Y', 4, false, tipoCam); //Monalisa
		Fruta3->Draw(camara->vista, camara->proyeccion, Fruta3->getPosX(), terreno->Superficie(-34.9, -28.8), Fruta3->getPosZ(), camara->posCam, 200.0f, 44.8, 'Y', 0.4, false, tipoCam); //El Beso-Manzana 
		Fruta4->Draw(camara->vista, camara->proyeccion, Fruta4->getPosX(), terreno->Superficie(-34.9, -28.8), Fruta4->getPosZ(), camara->posCam, 200.0f, 44.8, 'Y', 6, false, tipoCam); //La Joven de perla
		Fruta5->Draw(camara->vista, camara->proyeccion, Fruta5->getPosX(), terreno->Superficie(-34.9, 100), Fruta5->getPosZ(), camara->posCam, 200.0f, 44.8, 'Y', 8, false, tipoCam); //El Nacimiento de Venus
		Fruta6->Draw(camara->vista, camara->proyeccion, Fruta6->getPosX(), terreno->Superficie(-34.9, -28.8), Fruta6->getPosZ(), camara->posCam, 200.0f, 44.8, 'Y', 10, false, tipoCam); //El Hijo del Hombre
		Fruta7->Draw(camara->vista, camara->proyeccion, Fruta7->getPosX(), terreno->Superficie(-34.9, -28.8), Fruta7->getPosZ(), camara->posCam, 200.0f, 44.8, 'Y', 8, false, tipoCam); //El Grito
		Fruta8->Draw(camara->vista, camara->proyeccion, Fruta8->getPosX(), terreno->Superficie(-34.9, -28.8), Fruta8->getPosZ(), camara->posCam, 200.0f, 44.8, 'Y', 6, false, tipoCam); //Las 2 Fridas-Manzana verde
		Fruta9->Draw(camara->vista, camara->proyeccion, Fruta9->getPosX(), terreno->Superficie(-34.9, -28.8), Fruta9->getPosZ(), camara->posCam, 200.0f, 44.8, 'Y', 8, false, tipoCam); //La Creacion de Adam
		Fruta10->Draw(camara->vista, camara->proyeccion, Fruta10->getPosX(), terreno->Superficie(-14, -6), Fruta10->getPosZ(), camara->posCam, 200.0f, 44.8, 'Y', 14, false, tipoCam); //Guernica

		//CUADROS
		cuadro1->Draw(camara->vista, camara->proyeccion, cuadro1->getPosX(), terreno->Superficie(3.5, 78.3), cuadro1->getPosZ(), camara->posCam, 10.0f, 0, 'Y', 1, false, tipoCam); //La Noche Estrellada		
		cuadro10->Draw(camara->vista, camara->proyeccion, cuadro10->getPosX(), terreno->Superficie(49.5, 78.3), cuadro10->getPosZ(), camara->posCam, 10.0f, 0, 'Y', 1, false, tipoCam); //La Monalisa
		cuadro6->Draw(camara->vista, camara->proyeccion, cuadro6->getPosX(), terreno->Superficie(26.5, 78.3), cuadro6->getPosZ(), camara->posCam, 10.0f, 0, 'Y', 1, false, tipoCam); //El Beso
		cuadro9->Draw(camara->vista, camara->proyeccion, cuadro9->getPosX(), terreno->Superficie(43.5, 78.3), cuadro9->getPosZ(), camara->posCam, 10.0f, 0, 'Y', 1, false, tipoCam);//La Joven de Perla
		cuadro5->Draw(camara->vista, camara->proyeccion, cuadro5->getPosX(), terreno->Superficie(21.5, 78.3), cuadro5->getPosZ(), camara->posCam, 10.0f, 0, 'Y', 1, false, tipoCam);//El Nacimiento de Venus
		cuadro8->Draw(camara->vista, camara->proyeccion, cuadro8->getPosX(), terreno->Superficie(37.5, 78.3), cuadro8->getPosZ(), camara->posCam, 10.0f, 0, 'Y', 1, false, tipoCam);//El Hijo del Hombre
		cuadro7->Draw(camara->vista, camara->proyeccion, cuadro7->getPosX(), terreno->Superficie(32.5, 78.3), cuadro7->getPosZ(), camara->posCam, 10.0f, 0, 'Y', 1, false, tipoCam);//El grito
		cuadro4->Draw(camara->vista, camara->proyeccion, cuadro4->getPosX(), terreno->Superficie(15.5, 78.3), cuadro4->getPosZ(), camara->posCam, 10.0f, 0, 'Y', 1, false, tipoCam);//Las 2 Fridas
		cuadro3->Draw(camara->vista, camara->proyeccion, cuadro3->getPosX(), terreno->Superficie(-3.5, 78.3), cuadro3->getPosZ(), camara->posCam, 10.0f, 0, 'Y', 1, false, tipoCam);//La creacion de adam
		cuadro2->Draw(camara->vista, camara->proyeccion, cuadro2->getPosX(), terreno->Superficie(9.5, 78.3), cuadro2->getPosZ(), camara->posCam, 10.0f, 0, 'Y', 1, false, tipoCam);//Guernica
	 #pragma region Otros_Modelos

		//BANCAS
		banca->Draw(camara->vista, camara->proyeccion, -34.9, terreno->Superficie(-34.9, -28.8), -28.8, camara->posCam, 200.0f, 44.8, 'Y', 1, false, tipoCam);
		banca->Draw(camara->vista, camara->proyeccion, -44.8, terreno->Superficie(-44.8, -14.4), -14.4, camara->posCam, 200.0f, 45.2, 'Y', 1, false, tipoCam);
		banca->Draw(camara->vista, camara->proyeccion, -21.5, terreno->Superficie(-21.5, -90.6), -90.6, camara->posCam, 200.0f, 45.7, 'Y', 1, false, tipoCam);
		banca->Draw(camara->vista, camara->proyeccion, -29.4, terreno->Superficie(-29.4, -109.5),-109.5, camara->posCam, 200.0f, 46, 'Y', 1, false, tipoCam);
		banca->Draw(camara->vista, camara->proyeccion, -19.9, terreno->Superficie(-19.9, -26), -26, camara->posCam, 200.0f, -46.3, 'Y', 1, false, tipoCam);
		banca->Draw(camara->vista, camara->proyeccion, -18.2, terreno->Superficie(-18.2, -121.6), -121.6, camara->posCam, 200.0f, -45.7, 'Y', 1, false, tipoCam);
		banca->Draw(camara->vista, camara->proyeccion, -11.8, terreno->Superficie(-11.8, -108.1), -108.1, camara->posCam, 200.0f, -45.5, 'Y', 1, false, tipoCam);
		banca->Draw(camara->vista, camara->proyeccion, -93.2, terreno->Superficie(-93.2, -24.6), -24.6, camara->posCam, 200.0f, -19.4, 'Y', 1, false, tipoCam);
		banca->Draw(camara->vista, camara->proyeccion, -116.3, terreno->Superficie(-116.3, -39), -39, camara->posCam, 200.0f, -19.8, 'Y', 1, false, tipoCam);
		banca->Draw(camara->vista, camara->proyeccion, -55.6, terreno->Superficie(-55.6, 34.7), 34.7, camara->posCam, 200.0f, -3.8, 'Y', 1, false, tipoCam);
		banca->Draw(camara->vista, camara->proyeccion, -69.9, terreno->Superficie(-69.9, 15.4), 15.4, camara->posCam, 200.0f, -4, 'Y', 1, false, tipoCam);
		banca->Draw(camara->vista, camara->proyeccion, -124, terreno->Superficie(-124, -27.2), -27.2, camara->posCam, 200.0f, -4, 'Y', 1, false, tipoCam);
	
		banca->Draw(camara->vista, camara->proyeccion, -37.4, terreno->Superficie(-37.4, 61.4), 61.4, camara->posCam, 200.0f, -5, 'Y', 1, false, tipoCam);
		banca->Draw(camara->vista, camara->proyeccion, -36.3, terreno->Superficie(-36.3, 82.4), 82.4, camara->posCam, 200.0f, -4.2, 'Y', 1, false, tipoCam);
		banca->Draw(camara->vista, camara->proyeccion, -21.6, terreno->Superficie(-21.6, 52.1), 52.1, camara->posCam, 200.0f, 5.1, 'Y', 1, false, tipoCam);
		banca->Draw(camara->vista, camara->proyeccion, -33.5, terreno->Superficie(-33.5, 33.6), 33.6, camara->posCam, 200.0f, 5.8, 'Y', 1, false, tipoCam);
		banca->Draw(camara->vista, camara->proyeccion, 28.6, terreno->Superficie(28.6, 30.6), 30.6, camara->posCam, 200.0f, 4, 'Y', 1, false, tipoCam);
		banca->Draw(camara->vista, camara->proyeccion, 40.7, terreno->Superficie(40.7, -8.2), -8.2, camara->posCam, 200.0f, -5, 'Y', 1, false, tipoCam);
		
		banca->Draw(camara->vista, camara->proyeccion, 47.4, terreno->Superficie(47.4, -21.5), -21.5, camara->posCam, 200.0f, -4.8, 'Y', 1, false, tipoCam);
		banca->Draw(camara->vista, camara->proyeccion, 63.2, terreno->Superficie(63.2, -22.1), -22.1, camara->posCam, 200.0f, 4.6, 'Y', 1, false, tipoCam);
		banca->Draw(camara->vista, camara->proyeccion, 59.7, terreno->Superficie(59.7, -42.8), -42.8, camara->posCam, 200.0f, 5, 'Y', 1, false, tipoCam);
		banca->Draw(camara->vista, camara->proyeccion, 72.7, terreno->Superficie(72.7, -107.1), -107.1, camara->posCam, 200.0f, -5.4, 'Y', 1, false, tipoCam);
		banca->Draw(camara->vista, camara->proyeccion, 52.7, terreno->Superficie(52.7, -80.8), -80.8, camara->posCam, 200.0f, -5.3, 'Y', 1, false, tipoCam);
		banca->Draw(camara->vista, camara->proyeccion, 62.3, terreno->Superficie(62.3, 35.7), 35.7, camara->posCam, 200.0f, 3.5, 'Y', 1, false, tipoCam);
		banca->Draw(camara->vista, camara->proyeccion, 99.4, terreno->Superficie(99.4, 6.69), 6.69, camara->posCam, 200.0f, 3.5, 'Y', 1, false, tipoCam);

		//BOTES BASURA
		boteBasura->Draw(camara->vista, camara->proyeccion, 36.5, terreno->Superficie(36.5, 3.5), 3.5, camara->posCam, 200.0f, 0, 'A', 1, false, tipoCam);
		boteBasura->Draw(camara->vista, camara->proyeccion, 27.5, terreno->Superficie(27.5, 20.5), 20.5, camara->posCam, 200.0f, 0, 'A', 1, false, tipoCam);
		boteBasura->Draw(camara->vista, camara->proyeccion, 102.2, terreno->Superficie(102.2, -78.5), -78.5, camara->posCam, 200.0f, 0, 'A', 1, false, tipoCam);
		boteBasura->Draw(camara->vista, camara->proyeccion, -33.4, terreno->Superficie(-33.4, 56.2), 56.2, camara->posCam, 200.0f, 0, 'A', 1, false, tipoCam);
		boteBasura->Draw(camara->vista, camara->proyeccion, -45.5, terreno->Superficie(-45.5, 2.25), 2.25, camara->posCam, 200.0f, 0, 'A', 1, false, tipoCam);
		boteBasura->Draw(camara->vista, camara->proyeccion, -20.5, terreno->Superficie(-20.5, -70.5), -70.5, camara->posCam, 200.0f, 0, 'A', 1, false, tipoCam);
		
		//CABALLETES
		caballete->Draw(camara->vista, camara->proyeccion, 3.5, terreno->Superficie(3.5, 78.3), 78.3, camara->posCam, 10.0f, 0, 'Y', 1, false, tipoCam);
		caballete->Draw(camara->vista, camara->proyeccion, 9.5, terreno->Superficie(9.5, 78.3), 78.3, camara->posCam, 10.0f, 0, 'Y', 1, false, tipoCam);
		caballete->Draw(camara->vista, camara->proyeccion, -3.5, terreno->Superficie(-3.5, 78.3), 78.3, camara->posCam, 10.0f, 0, 'Y', 1, false, tipoCam);
		caballete->Draw(camara->vista, camara->proyeccion, 15.5, terreno->Superficie(15.5, 78.3), 78.3, camara->posCam, 10.0f, 0, 'Y', 1, false, tipoCam);
		caballete->Draw(camara->vista, camara->proyeccion, 21.5, terreno->Superficie(21.5, 78.3), 78.3, camara->posCam, 10.0f, 0, 'Y', 1, false, tipoCam);
		caballete->Draw(camara->vista, camara->proyeccion, 26.5, terreno->Superficie(26.5, 78.3), 78.3, camara->posCam, 10.0f, 0, 'Y', 1, false, tipoCam);
		caballete->Draw(camara->vista, camara->proyeccion, 32.5, terreno->Superficie(32.5, 78.3), 78.3, camara->posCam, 10.0f, 0, 'Y', 1, false, tipoCam);
		caballete->Draw(camara->vista, camara->proyeccion, 37.5, terreno->Superficie(37.5, 78.3), 78.3, camara->posCam, 10.0f, 0, 'Y', 1, false, tipoCam);
		caballete->Draw(camara->vista, camara->proyeccion, 43.5, terreno->Superficie(43.5, 78.3), 78.3, camara->posCam, 10.0f, 0, 'Y', 1, false, tipoCam);
		caballete->Draw(camara->vista, camara->proyeccion, 49.5, terreno->Superficie(49.5, 78.3), 78.3, camara->posCam, 10.0f, 0, 'Y', 1, false, tipoCam);
			
		//atril
		atril->Draw(camara->vista, camara->proyeccion, 3.1, terreno->Superficie(3.5, 70.3), 78.3, camara->posCam, 10.0f, 0, 'Y', 1, false, tipoCam);
		atril->Draw(camara->vista, camara->proyeccion, 9.5, terreno->Superficie(9.5, 78.3), 78.3, camara->posCam, 10.0f, 0, 'Y', 1, false, tipoCam);
		atril->Draw(camara->vista, camara->proyeccion, -3.5, terreno->Superficie(-3.5, 78.3), 78.3, camara->posCam, 10.0f, 0, 'Y', 1, false, tipoCam);
		atril->Draw(camara->vista, camara->proyeccion, 15.5, terreno->Superficie(15.5, 78.3), 78.3, camara->posCam, 10.0f, 0, 'Y', 1, false, tipoCam);
		atril->Draw(camara->vista, camara->proyeccion, 21.5, terreno->Superficie(21.5, 78.3), 78.3, camara->posCam, 10.0f, 0, 'Y', 1, false, tipoCam);
		atril->Draw(camara->vista, camara->proyeccion, 26.5, terreno->Superficie(26.5, 78.3), 78.3, camara->posCam, 10.0f, 0, 'Y', 1, false, tipoCam);
		atril->Draw(camara->vista, camara->proyeccion, 32.5, terreno->Superficie(32.5, 78.3), 78.3, camara->posCam, 10.0f, 0, 'Y', 1, false, tipoCam);
		atril->Draw(camara->vista, camara->proyeccion, 37.5, terreno->Superficie(37.5, 78.3), 78.3, camara->posCam, 10.0f, 0, 'Y', 1, false, tipoCam);
		atril->Draw(camara->vista, camara->proyeccion, 43.5, terreno->Superficie(43.5, 78.3), 78.3, camara->posCam, 10.0f, 0, 'Y', 1, false, tipoCam);
		atril->Draw(camara->vista, camara->proyeccion, 49.5, terreno->Superficie(49.5, 78.3), 78.3, camara->posCam, 10.0f, 0, 'Y', 1, false, tipoCam);

		//LAMPARAS
		lampara->Draw(camara->vista, camara->proyeccion, -55, terreno->Superficie(-55, 110), 110, camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		lampara->Draw(camara->vista, camara->proyeccion, -35, terreno->Superficie(-35, 130), 130, camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		lampara->Draw(camara->vista, camara->proyeccion, -75, terreno->Superficie(-75, 123), 123, camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		lampara->Draw(camara->vista, camara->proyeccion, -95, terreno->Superficie(-95, 110), 110, camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		lampara->Draw(camara->vista, camara->proyeccion, -115, terreno->Superficie(-115, 130), 125, camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		lampara->Draw(camara->vista, camara->proyeccion, -125, terreno->Superficie(-125, 110), 110, camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		lampara->Draw(camara->vista, camara->proyeccion, 35, terreno->Superficie(35, 95), 95, camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		lampara->Draw(camara->vista, camara->proyeccion, 55, terreno->Superficie(55, 74), 74, camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		lampara->Draw(camara->vista, camara->proyeccion, 75, terreno->Superficie(75, 95), 95, camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		lampara->Draw(camara->vista, camara->proyeccion, 95, terreno->Superficie(95, 92), 92, camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		lampara->Draw(camara->vista, camara->proyeccion, 115, terreno->Superficie(115, 123), 123, camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		lampara->Draw(camara->vista, camara->proyeccion, 55, terreno->Superficie(55, 117), 117, camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		lampara->Draw(camara->vista, camara->proyeccion, 37, terreno->Superficie(37, 25), 25, camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		lampara->Draw(camara->vista, camara->proyeccion, 70, terreno->Superficie(70, 32), 32, camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		lampara->Draw(camara->vista, camara->proyeccion, 90, terreno->Superficie(90, 8)-1, 8, camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		lampara->Draw(camara->vista, camara->proyeccion, 110, terreno->Superficie(110, 22), 22, camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		lampara->Draw(camara->vista, camara->proyeccion, 130, terreno->Superficie(130, 0), 0, camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		lampara->Draw(camara->vista, camara->proyeccion, 35, terreno->Superficie(35, 0), 0, camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		lampara->Draw(camara->vista, camara->proyeccion, 62, terreno->Superficie(62, -13), -13, camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		lampara->Draw(camara->vista, camara->proyeccion, 48, terreno->Superficie(48, -33), -33, camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		lampara->Draw(camara->vista, camara->proyeccion, 61, terreno->Superficie(61, -53), -53, camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		lampara->Draw(camara->vista, camara->proyeccion, 49, terreno->Superficie(49, -73), -73, camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		lampara->Draw(camara->vista, camara->proyeccion, 83, terreno->Superficie(83, -93), -93, camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		lampara->Draw(camara->vista, camara->proyeccion, 78, terreno->Superficie(78, -113), -113, camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		lampara->Draw(camara->vista, camara->proyeccion, -30, terreno->Superficie(-30, 95), 95, camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		lampara->Draw(camara->vista, camara->proyeccion, -23, terreno->Superficie(-23, 65), 65, camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		lampara->Draw(camara->vista, camara->proyeccion, -47, terreno->Superficie(-47, 45), 45, camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		lampara->Draw(camara->vista, camara->proyeccion, -50, terreno->Superficie(-50,0), 0, camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		lampara->Draw(camara->vista, camara->proyeccion, -45, terreno->Superficie(-50, 0), 20, camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		lampara->Draw(camara->vista, camara->proyeccion, -75, terreno->Superficie(-62, 20), 5, camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		lampara->Draw(camara->vista, camara->proyeccion, -85, terreno->Superficie(-85, -20), -20, camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		lampara->Draw(camara->vista, camara->proyeccion, -115, terreno->Superficie(-115, -22), -22, camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		lampara->Draw(camara->vista, camara->proyeccion, -125, terreno->Superficie(-125, -55), -55, camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		lampara->Draw(camara->vista, camara->proyeccion, lampara->getPosX(), terreno->Superficie(lampara->getPosX(), lampara->getPosZ()), lampara->getPosZ(), camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		lampara->Draw(camara->vista, camara->proyeccion, -30, terreno->Superficie(-30,-40), -40, camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		lampara->Draw(camara->vista, camara->proyeccion, -7, terreno->Superficie(-7, -60), -60, camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		lampara->Draw(camara->vista, camara->proyeccion, -20, terreno->Superficie(-20, -80), -80, camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		lampara->Draw(camara->vista, camara->proyeccion, -10, terreno->Superficie(-10, -100), -100, camara->posCam, 10.0f,0, 'A', 1, false, tipoCam);
		lampara->Draw(camara->vista, camara->proyeccion, -35, terreno->Superficie(-10, -100), -120, camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		
		//MESAS DE PICNIC
		mesaPicnic->Draw(camara->vista, camara->proyeccion, mesaPicnic->getPosX(), terreno->Superficie(mesaPicnic->getPosX(), mesaPicnic->getPosZ()), mesaPicnic->getPosZ(), camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		mesaPicnic->Draw(camara->vista, camara->proyeccion, 100, terreno->Superficie(100, -60), -60, camara->posCam, 10.0f, -45, 'Y', 1, false, tipoCam);
		mesaPicnic->Draw(camara->vista, camara->proyeccion, 80, terreno->Superficie(80, -40), -40, camara->posCam, 10.0f, -30, 'Y', 1, false, tipoCam);
		mesaPicnic->Draw(camara->vista, camara->proyeccion, 80, terreno->Superficie(80, -60), -60, camara->posCam, 10.0f, 45, 'Y', 1, false, tipoCam);
		mesaPicnic->Draw(camara->vista, camara->proyeccion, 105, terreno->Superficie(105, -75), -75, camara->posCam, 10.0f, 0, 'Y', 1, false, tipoCam);
		mesaPicnic->Draw(camara->vista, camara->proyeccion, 110, terreno->Superficie(110, -50), -50, camara->posCam, 10.0f, 0, 'Y', 1, false, tipoCam);
		
		//MUSEO
		museo->Draw(camara->vista, camara->proyeccion, museo->getPosX(), terreno->Superficie(museo->getPosX(), museo->getPosZ()), museo->getPosZ(), camara->posCam, 5.0f, 0, 'A', 8, false, tipoCam);
		
		//PUESTO
		puesto->Draw(camara->vista, camara->proyeccion, puesto->getPosX(), terreno->Superficie(puesto->getPosX(), puesto->getPosZ()), puesto->getPosZ(),camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		computadora->Draw(camara->vista, camara->proyeccion, computadora->getPosX(), terreno->Superficie(computadora->getPosX(), computadora->getPosZ()), computadora->getPosZ(), camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		escurridor->Draw(camara->vista, camara->proyeccion, escurridor->getPosX(), terreno->Superficie(escurridor->getPosX(), escurridor->getPosZ()), escurridor->getPosZ(), camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		estanterias->Draw(camara->vista, camara->proyeccion, estanterias->getPosX(),terreno->Superficie(estanterias->getPosX(), estanterias->getPosZ()),  estanterias->getPosZ(), camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		exhibidor->Draw(camara->vista, camara->proyeccion, exhibidor->getPosX(), terreno->Superficie(exhibidor->getPosX(), exhibidor->getPosZ()), exhibidor->getPosZ(), camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		lamparas->Draw(camara->vista, camara->proyeccion, lamparas->getPosX(), terreno->Superficie(lamparas->getPosX(), lamparas->getPosZ()), lamparas->getPosZ(),camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		lavabo->Draw(camara->vista, camara->proyeccion, lavabo->getPosX(), terreno->Superficie(lavabo->getPosX(), lavabo->getPosZ()), lavabo->getPosZ(), camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		muebles->Draw(camara->vista, camara->proyeccion, muebles->getPosX(), terreno->Superficie(muebles->getPosX(), muebles->getPosZ()), muebles->getPosZ(), camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		platosEscurridor->Draw(camara->vista, camara->proyeccion, platosEscurridor->getPosX(), terreno->Superficie(platosEscurridor->getPosX(), platosEscurridor->getPosZ()), platosEscurridor->getPosZ(), camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		platosTazas->Draw(camara->vista, camara->proyeccion, platosTazas->getPosX(), terreno->Superficie(platosTazas->getPosX(), platosTazas->getPosZ()), platosTazas->getPosZ(), camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		puerta->Draw(camara->vista, camara->proyeccion, puerta->getPosX(), terreno->Superficie(puerta->getPosX(), puerta->getPosZ()), puerta->getPosZ(), camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		utensilios1->Draw(camara->vista, camara->proyeccion, utensilios1->getPosX(),terreno->Superficie(utensilios1->getPosX(), utensilios1->getPosZ()),  utensilios1->getPosZ(), camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		utensilios3->Draw(camara->vista, camara->proyeccion,  utensilios3->getPosX(), terreno->Superficie(utensilios3->getPosX(), utensilios3->getPosZ()), utensilios3->getPosZ(), camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);

		//ESTATUAS
		venus->Draw(camara->vista, camara->proyeccion, 10, terreno->Superficie(10, 10), 10, camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		discolombus->Draw(camara->vista, camara->proyeccion, discolombus->getPosX(), terreno->Superficie(discolombus->getPosX(), discolombus->getPosZ()), discolombus->getPosZ(), camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);
		zeus->Draw(camara->vista, camara->proyeccion, zeus->getPosX(), terreno->Superficie(zeus->getPosX(), zeus->getPosZ()), zeus->getPosZ(), camara->posCam, 10.0f, 0, 'A', 1, false, tipoCam);


		//BILLBOARDS
		arbol->Draw(camara->vista, camara->proyeccion, camara->posCam,
			-11, 78, terreno->Superficie(-11, 78), 8, uv1, uv2, uv3, uv4, frameBillboard, false);
		arbol2->Draw(camara->vista, camara->proyeccion, camara->posCam,
			22, -78, terreno->Superficie(22, 78), 8, uv1, uv2, uv3, uv4, frameBillboard, false);
		arbol->Draw(camara->vista, camara->proyeccion, camara->posCam,
			105, -25, terreno->Superficie(105, -25), 8, uv1, uv2, uv3, uv4, frameBillboard, false);
		arbol2->Draw(camara->vista, camara->proyeccion, camara->posCam,
			-108, 67, terreno->Superficie(22, 78), 8, uv1, uv2, uv3, uv4, frameBillboard, false);
		arbol->Draw(camara->vista, camara->proyeccion, camara->posCam,
			-75, -120, terreno->Superficie(105, -25), 8, uv1, uv2, uv3, uv4, frameBillboard, false);
		arbol2->Draw(camara->vista, camara->proyeccion, camara->posCam,
			94, 79, terreno->Superficie(22, 78), 8, uv1, uv2, uv3, uv4, frameBillboard, false);
		arbol->Draw(camara->vista, camara->proyeccion, camara->posCam,
			16, -24, terreno->Superficie(105, -25), 8, uv1, uv2, uv3, uv4, frameBillboard, false);

		arbusto->Draw(camara->vista, camara->proyeccion, camara->posCam,
			3, -75, terreno->Superficie(3, -75), 2, uv1, uv2, uv3, uv4, frameBillboard, false);
		arbusto->Draw(camara->vista, camara->proyeccion, camara->posCam,
			103, -37, terreno->Superficie(103, -37), 2, uv1, uv2, uv3, uv4, frameBillboard, false);
		arbusto->Draw(camara->vista, camara->proyeccion, camara->posCam,
			73, 53, terreno->Superficie(73, 53), 2, uv1, uv2, uv3, uv4, frameBillboard, false);
		arbusto->Draw(camara->vista, camara->proyeccion, camara->posCam,
			-10, 37, terreno->Superficie(-10, 37), 2, uv1, uv2, uv3, uv4, frameBillboard, false);
		arbusto->Draw(camara->vista, camara->proyeccion, camara->posCam,
			-73, 49, terreno->Superficie(-10, 37), 2, uv1, uv2, uv3, uv4, frameBillboard, false);
		arbusto->Draw(camara->vista, camara->proyeccion, camara->posCam,
			-69, -35, terreno->Superficie(-69, -35), 2, uv1, uv2, uv3, uv4, frameBillboard, false);

#pragma endregion 

#pragma region Colisiones

		if (tipoCam == 1) {

			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Notas
			float radionotas = 3;

			//Fruta1
			if (isPointInsideSphere(camara->getPos(), Fruta1->getSphere(radionotas, Fruta1->getPosX(), Fruta1->getPosZ()))) {
				ima->Set_Imagen(*nota_1_imagen, 1);
				status = true;

				//if (!effectDone) {
				//	m_XACT3.m_pSoundBank->Play(cueIndex,0, 0, 0);
				//	effectDone = true;
				//}
				camara->posCam = camara->posCamPast;
			}

			//Fruta2
			if (isPointInsideSphere(camara->getPos(), Fruta2->getSphere(radionotas, Fruta2->getPosX(), Fruta2->getPosZ()))) {
				ima->Set_Imagen(*nota_2_imagen, 2);
				status = true;
				camara->posCam = camara->posCamPast;
			}
			
			//Fruta3
			if (isPointInsideSphere(camara->getPos(), Fruta3->getSphere(radionotas, Fruta3->getPosX(), Fruta3->getPosZ()))) {
				ima->Set_Imagen(*nota_3_imagen, 3);
				status = true;
				camara->posCam = camara->posCamPast;
			}

			//Fruta4
			if (isPointInsideSphere(camara->getPos(), Fruta4->getSphere(radionotas, Fruta4->getPosX(), Fruta4->getPosZ()))) {
				ima->Set_Imagen(*nota_4_imagen, 4);
				status = true;
				camara->posCam = camara->posCamPast;
			}

			//Fruta5
			if (isPointInsideSphere(camara->getPos(), Fruta5->getSphere(radionotas, Fruta5->getPosX(), Fruta5->getPosZ()))) {
				ima->Set_Imagen(*nota_5_imagen, 5);
				status = true;
				camara->posCam = camara->posCamPast;
			}

			//Fruta6
			if (isPointInsideSphere(camara->getPos(), Fruta6->getSphere(radionotas, Fruta6->getPosX(), Fruta6->getPosZ()))) {
				ima->Set_Imagen(*nota_6_imagen, 6);
				status = true;
				camara->posCam = camara->posCamPast;
			}

			//Fruta7
			if (isPointInsideSphere(camara->getPos(), Fruta7->getSphere(radionotas, Fruta7->getPosX(), Fruta7->getPosZ()))) {
				ima->Set_Imagen(*nota_7_imagen, 7);
				status = true;
				camara->posCam = camara->posCamPast;
			}

			//Fruta8
			if (isPointInsideSphere(camara->getPos(), Fruta8->getSphere(radionotas, Fruta8->getPosX(), Fruta8->getPosZ()))) {
				ima->Set_Imagen(*nota_8_imagen, 8);
				status = true;
				camara->posCam = camara->posCamPast;
			}

			//Fruta9
			if (isPointInsideSphere(camara->getPos(), Fruta9->getSphere(radionotas, Fruta9->getPosX(), Fruta9->getPosZ()))) {
				ima->Set_Imagen(*nota_9_imagen, 9);
				status = true;
				camara->posCam = camara->posCamPast;
			}

			//Fruta10
			if (isPointInsideSphere(camara->getPos(), Fruta10->getSphere(radionotas, Fruta10->getPosX(), Fruta10->getPosZ()))) {
				ima->Set_Imagen(*nota_10_imagen, 10);
				status = true;
				camara->posCam = camara->posCamPast;
			}

			if (status) { //the gui
				ima->Draw();
			}

			if (status2) {
				ima->Draw_Supreme();
			}

			//////////
			//Cuadros
			//////////
			float cuadros = 4;

			if (isPointInsideSphere(camara->getPos(), cuadro1->getSphere(cuadros, 3.5, 78.3))) { //Fruta1
				int id_noche_estrellada = 1;
				bool respuesta = ima->validar_pinturas(id_noche_estrellada);

				if (respuesta) {
					//means it's ok
					cuadro1->setPosX(5000);
					ima->Free_Gui();
					Fruta1->setPosX(5000);
				}
				else {
					bool status = ima->check_if_i_have_a_note();

					if(status) {
						ima->Set_Imagen_Incorrecta(*Nota_Incorrecta);
						ima->Draw_Incorrect_Image();
					}
				}
				camara->posCam = camara->posCamPast;
			}

			if (isPointInsideSphere(camara->getPos(), cuadro10->getSphere(cuadros, 49.5, 78.3))) { //Fruta2
				int id_monalisa = 2;
				bool respuesta = ima->validar_pinturas(id_monalisa);

				if (respuesta) {
					//means it's ok
					cuadro10->setPosX(5000);
					ima->Free_Gui();
					Fruta2->setPosX(5000);
				}
				else {
					bool status = ima->check_if_i_have_a_note();

					if (status) {
						ima->Set_Imagen_Incorrecta(*Nota_Incorrecta);
						ima->Draw_Incorrect_Image();
					}
				}
				camara->posCam = camara->posCamPast;
			}

			if (isPointInsideSphere(camara->getPos(), cuadro6->getSphere(cuadros, 26.5, 78.3))) { //Fruta3
				
				int id_beso = 3;
				bool respuesta = ima->validar_pinturas(id_beso);

				if (respuesta) {
					//means it's ok
					cuadro6->setPosX(5000);
					ima->Free_Gui();
					Fruta3->setPosX(5000);
				}
				else {
					bool status = ima->check_if_i_have_a_note();

					if (status) {
						ima->Set_Imagen_Incorrecta(*Nota_Incorrecta);
						ima->Draw_Incorrect_Image();
					}
				}
				camara->posCam = camara->posCamPast;
			}

			if (isPointInsideSphere(camara->getPos(), cuadro9->getSphere(cuadros, 43.5, 78.3))) {//Fruta4
				int id = 4;
				bool respuesta = ima->validar_pinturas(id);

				if (respuesta) {
					//means it's ok
					cuadro9->setPosX(5000);
					ima->Free_Gui();
					Fruta4->setPosX(5000);
				}
				else {
					bool status = ima->check_if_i_have_a_note();

					if (status) {
						ima->Set_Imagen_Incorrecta(*Nota_Incorrecta);
						ima->Draw_Incorrect_Image();
					}
				}
				camara->posCam = camara->posCamPast;
			}

			if (isPointInsideSphere(camara->getPos(), cuadro5->getSphere(cuadros, 21.5, 78.3))) {//Fruta5
				int id = 5;
				bool respuesta = ima->validar_pinturas(id);

				if (respuesta) {
					//means it's ok
					cuadro5->setPosX(5000);
					ima->Free_Gui();
					Fruta5->setPosX(5000);
				}
				else {
					bool status = ima->check_if_i_have_a_note();

					if (status) {
						ima->Set_Imagen_Incorrecta(*Nota_Incorrecta);
						ima->Draw_Incorrect_Image();
					}
				}
				camara->posCam = camara->posCamPast;
			}

			if (isPointInsideSphere(camara->getPos(), cuadro8->getSphere(cuadros, 37.5, 78.3))) {//Fruta6
				int id = 6;
				bool respuesta = ima->validar_pinturas(id);

				if (respuesta) {
					//means it's ok
					cuadro8->setPosX(5000);
					ima->Free_Gui();
					Fruta6->setPosX(5000);
				}
				else {
					bool status = ima->check_if_i_have_a_note();

					if (status) {
						ima->Set_Imagen_Incorrecta(*Nota_Incorrecta);
						ima->Draw_Incorrect_Image();
					}
				}
				camara->posCam = camara->posCamPast;
			}

			if (isPointInsideSphere(camara->getPos(), cuadro7->getSphere(cuadros, 32.5, 78.3))) {//Fruta7
				int id = 7;
				bool respuesta = ima->validar_pinturas(id);

				if (respuesta) {
					//means it's ok
					cuadro7->setPosX(5000);
					ima->Free_Gui();
					Fruta7->setPosX(5000);
				}
				else {
					bool status = ima->check_if_i_have_a_note();

					if (status) {
						ima->Set_Imagen_Incorrecta(*Nota_Incorrecta);
						ima->Draw_Incorrect_Image();
					}
				}
				camara->posCam = camara->posCamPast;
			}

			if (isPointInsideSphere(camara->getPos(), cuadro4->getSphere(cuadros, 15.5, 78.3))) {//Fruta8
				int id = 8;
				bool respuesta = ima->validar_pinturas(id);

				if (respuesta) {
					//means it's ok
					cuadro4->setPosX(5000);
					ima->Free_Gui();
					Fruta8->setPosX(5000);
				}
				else {
					bool status = ima->check_if_i_have_a_note();

					if (status) {
						ima->Set_Imagen_Incorrecta(*Nota_Incorrecta);
						ima->Draw_Incorrect_Image();
					}
				}
				camara->posCam = camara->posCamPast;
			}

			if (isPointInsideSphere(camara->getPos(), cuadro3->getSphere(cuadros, -3.5, 78.3))) { //Fruta9
				int id = 9;
				bool respuesta = ima->validar_pinturas(id);

				if (respuesta) {
					//means it's ok
					cuadro3->setPosX(5000);
					ima->Free_Gui();
					Fruta9->setPosX(5000);
				}
				else {
					bool status = ima->check_if_i_have_a_note();

					if (status) {
						ima->Set_Imagen_Incorrecta(*Nota_Incorrecta);
						ima->Draw_Incorrect_Image();
					}
				}
				camara->posCam = camara->posCamPast;
			}

			if (isPointInsideSphere(camara->getPos(), cuadro2->getSphere(cuadros, 9.5, 78.3))) {//Fruta10

				int id = 10;
				bool respuesta = ima->validar_pinturas(id);

				if (respuesta) {
					//means it's ok
					cuadro2->setPosX(5000);
					ima->Free_Gui();
					Fruta10->setPosX(5000);
				}
				else {
					bool status = ima->check_if_i_have_a_note();

					if (status) {
						ima->Set_Imagen_Incorrecta(*Nota_Incorrecta);
						ima->Draw_Incorrect_Image();
					}
				}
				camara->posCam = camara->posCamPast;
			}

			/////////////////////////////////////////////////////////////////////////////////////// IF WIN

			if (Fruta1->getPosX() == 5000 && Fruta2->getPosX() == 5000 && Fruta3->getPosX() == 5000 &&
				Fruta4->getPosX() == 5000 && Fruta5->getPosX() == 5000 && Fruta6->getPosX() == 5000 &&
				Fruta7->getPosX() == 5000 && Fruta8->getPosX() == 5000 && Fruta9->getPosX() == 5000 && Fruta10->getPosX() == 5000) {
				ima->Set_Imagen(*Nota_Ganar, 11);
				ima->Ganar();
			}

			if (segundos <= 0) {
				ima->Set_Imagen(*Nota_Perder, 12);
				ima->Ganar();
				segundos = 0;
			}

			//Bancas

			float radiobancas = 4;

			if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, -34.9, -28.8))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, -44.8, -14.4))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, -21.5, -90.6))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, -29.4, -109.5))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, -19.9, -26))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, -18.2, -121.6))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, -11.8, -108.1))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, -93.2, -24.6))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, -116.3, -39))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, -55.6, 34.7))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, -69.9, 15.4))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, -124, -27.2))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, -37.4, 61.4))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, -36.3, 82.4))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, -21.6, 52.1))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, -33.5, 33.6))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, 28.6, 30.6))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, 40.7, -8.2))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, 47.4, -21.5))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, 63.2, -22.1))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, 59.7, -42.8))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, 72.7, -107.1))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, 52.7, -80.8))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, 62.3, 35.7))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, 99.4, 6.69))) {
				camara->posCam = camara->posCamPast;
			}

			//Lamparas
			float rLamparas = 3;

			
			if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -55, 110))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -35, 130))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -75, 123))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -95, 110))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -115, 130))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -125, 110))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, 35, 95))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, 55, 74))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, 75, 95))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, 95, 92))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, 115, 123))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, 55, 117))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, 37, 25))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, 70, 32))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, 90, 8))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, 110, 22))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, 130, 0))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, 35, 0))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, 62, -13))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, 48, -33))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, 61, -53))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, 49, -73))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, 83, -93))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, 78, -113))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -30, 95))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -23, 65))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -47, 45))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -50, 0))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -45, 20))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -62, 20))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -85, -20))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -115, -22))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -125, -55))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -25, -15))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -30, -40))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -7, -60))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -20, -80))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -10, -100))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -10, -100))) {
				camara->posCam = camara->posCamPast;
			}

			//Botes de basura
			float botesBasura = 4;
			if (isPointInsideSphere(camara->getPos(), boteBasura->getSphere(botesBasura, 36.5, 3.5))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), boteBasura->getSphere(botesBasura, 27.5, 20.5))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), boteBasura->getSphere(botesBasura, 102.2, -78.5))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), boteBasura->getSphere(botesBasura, -33.4, 56.2))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), boteBasura->getSphere(botesBasura, -45.5, 2.25))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), boteBasura->getSphere(botesBasura, -20.5, -70.5))) {
				camara->posCam = camara->posCamPast;
			}


			//Mesa picnic
			float rMesaPicnic = 4;

			if (isPointInsideSphere(camara->getPos(), mesaPicnic->getSphere(rMesaPicnic, 80, -80))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), mesaPicnic->getSphere(rMesaPicnic, 100, -60))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), mesaPicnic->getSphere(rMesaPicnic, 80, -40))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), mesaPicnic->getSphere(rMesaPicnic, 80, -60))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), mesaPicnic->getSphere(rMesaPicnic, 105, -75))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), mesaPicnic->getSphere(rMesaPicnic, 110, -50))) {
				camara->posCam = camara->posCamPast;
			}

			//Puesto

			if (isPointInsideSphere(camara->getPos(), puesto->getSphere(11, 100, -90))) {
				camara->posCam = camara->posCamPast;
			}

			//Museo
			if (isPointInsideSphere(camara->getPos(), museo->getSphere(25, -0, 110))) {
				camara->posCam = camara->posCamPast;
			}

			//Estatuas
			if (isPointInsideSphere(camara->getPos(), zeus->getSphere(4, zeus->getPosX(), zeus->getPosZ()))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), discolombus->getSphere(4, discolombus->getPosX(), discolombus->getPosZ()))) {
				camara->posCam = camara->posCamPast;
			}
			if (isPointInsideSphere(camara->getPos(), venus->getSphere(4, venus->getPosX(), venus->getPosZ()))) {
				camara->posCam = camara->posCamPast;
			}

		}
		else  if (tipoCam == 3) {

		float radionotas = 10;

		//Fruta1
		if (isPointInsideSphere(camara->getPos(), Fruta1->getSphere(radionotas, Fruta1->getPosX(), Fruta1->getPosZ()))) {
			ima->Set_Imagen(*nota_1_imagen, 1);
			status = true;

			if (!effectDone) {
				m_XACT3.m_pSoundBank->Play(cueIndex, 0, 0, 0);
				effectDone = true;
			}
			camara->posCam = camara->posCamPast;
		}

		//Fruta2
		if (isPointInsideSphere(camara->getPos(), Fruta2->getSphere(radionotas, Fruta2->getPosX(), Fruta2->getPosZ()))) {
			ima->Set_Imagen(*nota_2_imagen, 2);
			status = true;
			camara->posCam = camara->posCamPast;
		}

		//Fruta3
		if (isPointInsideSphere(camara->getPos(), Fruta3->getSphere(radionotas, Fruta3->getPosX(), Fruta3->getPosZ()))) {
			ima->Set_Imagen(*nota_3_imagen, 3);
			status = true;
			camara->posCam = camara->posCamPast;
		}

		//Fruta4
		if (isPointInsideSphere(camara->getPos(), Fruta4->getSphere(radionotas, Fruta4->getPosX(), Fruta4->getPosZ()))) {
			ima->Set_Imagen(*nota_4_imagen, 4);
			status = true;
			camara->posCam = camara->posCamPast;
		}

		//Fruta5
		if (isPointInsideSphere(camara->getPos(), Fruta5->getSphere(radionotas, Fruta5->getPosX(), Fruta5->getPosZ()))) {
			ima->Set_Imagen(*nota_5_imagen, 5);
			status = true;
			camara->posCam = camara->posCamPast;
		}

		//Fruta6
		if (isPointInsideSphere(camara->getPos(), Fruta6->getSphere(radionotas, Fruta6->getPosX(), Fruta6->getPosZ()))) {
			ima->Set_Imagen(*nota_6_imagen, 6);
			status = true;
			camara->posCam = camara->posCamPast;
		}

		//Fruta7
		if (isPointInsideSphere(camara->getPos(), Fruta7->getSphere(radionotas, Fruta7->getPosX(), Fruta7->getPosZ()))) {
			ima->Set_Imagen(*nota_7_imagen, 7);
			status = true;
			camara->posCam = camara->posCamPast;
		}

		//Fruta8
		if (isPointInsideSphere(camara->getPos(), Fruta8->getSphere(radionotas, Fruta8->getPosX(), Fruta8->getPosZ()))) {
			ima->Set_Imagen(*nota_8_imagen, 8);
			status = true;
			camara->posCam = camara->posCamPast;
		}

		//Fruta9
		if (isPointInsideSphere(camara->getPos(), Fruta9->getSphere(radionotas, Fruta9->getPosX(), Fruta9->getPosZ()))) {
			ima->Set_Imagen(*nota_9_imagen, 9);
			status = true;
			camara->posCam = camara->posCamPast;
		}

		//Fruta10
		if (isPointInsideSphere(camara->getPos(), Fruta10->getSphere(radionotas, Fruta10->getPosX(), Fruta10->getPosZ()))) {
			ima->Set_Imagen(*nota_10_imagen, 10);
			status = true;
			camara->posCam = camara->posCamPast;
		}

		if (status) { //the gui
			ima->Draw();
		}

		if (status2) {
			ima->Draw_Supreme();
		}

		//////////
		//Cuadros
		//////////
		float cuadros = 4;

		if (isPointInsideSphere(camara->getPos(), cuadro1->getSphere(cuadros, 3.5, 78.3))) { //Fruta1
			int id_noche_estrellada = 1;
			bool respuesta = ima->validar_pinturas(id_noche_estrellada);

			if (respuesta) {
				//means it's ok
				cuadro1->setPosX(5000);
				ima->Free_Gui();
				Fruta1->setPosX(5000);
			}
			else {
				bool status = ima->check_if_i_have_a_note();

				if (status) {
					ima->Set_Imagen_Incorrecta(*Nota_Incorrecta);
					ima->Draw_Incorrect_Image();
				}
			}
			camara->posCam = camara->posCamPast;
		}

		if (isPointInsideSphere(camara->getPos(), cuadro10->getSphere(cuadros, 49.5, 78.3))) { //Fruta2
			int id_monalisa = 2;
			bool respuesta = ima->validar_pinturas(id_monalisa);

			if (respuesta) {
				//means it's ok
				cuadro10->setPosX(5000);
				ima->Free_Gui();
				Fruta2->setPosX(5000);
			}
			else {
				bool status = ima->check_if_i_have_a_note();

				if (status) {
					ima->Set_Imagen_Incorrecta(*Nota_Incorrecta);
					ima->Draw_Incorrect_Image();
				}
			}
			camara->posCam = camara->posCamPast;
		}

		if (isPointInsideSphere(camara->getPos(), cuadro6->getSphere(cuadros, 26.5, 78.3))) { //Fruta3

			int id_beso = 3;
			bool respuesta = ima->validar_pinturas(id_beso);

			if (respuesta) {
				//means it's ok
				cuadro6->setPosX(5000);
				ima->Free_Gui();
				Fruta3->setPosX(5000);
			}
			else {
				bool status = ima->check_if_i_have_a_note();

				if (status) {
					ima->Set_Imagen_Incorrecta(*Nota_Incorrecta);
					ima->Draw_Incorrect_Image();
				}
			}
			camara->posCam = camara->posCamPast;
		}

		if (isPointInsideSphere(camara->getPos(), cuadro9->getSphere(cuadros, 43.5, 78.3))) {//Fruta4
			int id = 4;
			bool respuesta = ima->validar_pinturas(id);

			if (respuesta) {
				//means it's ok
				cuadro9->setPosX(5000);
				ima->Free_Gui();
				Fruta4->setPosX(5000);
			}
			else {
				bool status = ima->check_if_i_have_a_note();

				if (status) {
					ima->Set_Imagen_Incorrecta(*Nota_Incorrecta);
					ima->Draw_Incorrect_Image();
				}
			}
			camara->posCam = camara->posCamPast;
		}

		if (isPointInsideSphere(camara->getPos(), cuadro5->getSphere(cuadros, 21.5, 78.3))) {//Fruta5
			int id = 5;
			bool respuesta = ima->validar_pinturas(id);

			if (respuesta) {
				//means it's ok
				cuadro5->setPosX(5000);
				ima->Free_Gui();
				Fruta5->setPosX(5000);
			}
			else {
				bool status = ima->check_if_i_have_a_note();

				if (status) {
					ima->Set_Imagen_Incorrecta(*Nota_Incorrecta);
					ima->Draw_Incorrect_Image();
				}
			}
			camara->posCam = camara->posCamPast;
		}

		if (isPointInsideSphere(camara->getPos(), cuadro8->getSphere(cuadros, 37.5, 78.3))) {//Fruta6
			int id = 6;
			bool respuesta = ima->validar_pinturas(id);

			if (respuesta) {
				//means it's ok
				cuadro8->setPosX(5000);
				ima->Free_Gui();
				Fruta6->setPosX(5000);
			}
			else {
				bool status = ima->check_if_i_have_a_note();

				if (status) {
					ima->Set_Imagen_Incorrecta(*Nota_Incorrecta);
					ima->Draw_Incorrect_Image();
				}
			}
			camara->posCam = camara->posCamPast;
		}

		if (isPointInsideSphere(camara->getPos(), cuadro7->getSphere(cuadros, 32.5, 78.3))) {//Fruta7
			int id = 7;
			bool respuesta = ima->validar_pinturas(id);

			if (respuesta) {
				//means it's ok
				cuadro7->setPosX(5000);
				ima->Free_Gui();
				Fruta7->setPosX(5000);
			}
			else {
				bool status = ima->check_if_i_have_a_note();

				if (status) {
					ima->Set_Imagen_Incorrecta(*Nota_Incorrecta);
					ima->Draw_Incorrect_Image();
				}
			}
			camara->posCam = camara->posCamPast;
		}

		if (isPointInsideSphere(camara->getPos(), cuadro4->getSphere(cuadros, 15.5, 78.3))) {//Fruta8
			int id = 8;
			bool respuesta = ima->validar_pinturas(id);

			if (respuesta) {
				//means it's ok
				cuadro4->setPosX(5000);
				ima->Free_Gui();
				Fruta8->setPosX(5000);
			}
			else {
				bool status = ima->check_if_i_have_a_note();

				if (status) {
					ima->Set_Imagen_Incorrecta(*Nota_Incorrecta);
					ima->Draw_Incorrect_Image();
				}
			}
			camara->posCam = camara->posCamPast;
		}

		if (isPointInsideSphere(camara->getPos(), cuadro3->getSphere(cuadros, -3.5, 78.3))) {
			int id = 9;
			bool respuesta = ima->validar_pinturas(id);

			if (respuesta) {
				//means it's ok
				cuadro3->setPosX(5000);
				ima->Free_Gui();
				Fruta9->setPosX(5000);
			}
			else {
				bool status = ima->check_if_i_have_a_note();

				if (status) {
					ima->Set_Imagen_Incorrecta(*Nota_Incorrecta);
					ima->Draw_Incorrect_Image();
				}
			}
			camara->posCam = camara->posCamPast;
		}

		if (isPointInsideSphere(camara->getPos(), cuadro2->getSphere(cuadros, 9.5, 78.3))) {//Guernica

			int id = 10;
			bool respuesta = ima->validar_pinturas(id);

			if (respuesta) {
				//means it's ok
				cuadro2->setPosX(5000);
				ima->Free_Gui();
				Fruta10->setPosX(5000);
			}
			else {
				bool status = ima->check_if_i_have_a_note();

				if (status) {
					ima->Set_Imagen_Incorrecta(*Nota_Incorrecta);
					ima->Draw_Incorrect_Image();
				}
			}
			camara->posCam = camara->posCamPast;
		}

		/////////////////////////////////////////////////////////////////////////////////////// IF WIN

		if (Fruta1->getPosX() == 5000 && Fruta2->getPosX() == 5000 && Fruta3->getPosX() == 5000 &&
			Fruta4->getPosX() == 5000 && Fruta5->getPosX() == 5000 && Fruta6->getPosX() == 5000 &&
			Fruta7->getPosX() == 5000 && Fruta8->getPosX() == 5000 && Fruta9->getPosX() == 5000 && 
			Fruta10->getPosX() == 5000) {
			ima->Set_Imagen(*Nota_Ganar, 11);
			ima->Ganar();
		}

		if (segundos <= 0) {
			ima->Set_Imagen(*Nota_Perder, 12);
			ima->Ganar();
		}

		//Bancas

		float radiobancas = 6;

		if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, -34.9, -28.8))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, -44.8, -14.4))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, -21.5, -90.6))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, -29.4, -109.5))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, -19.9, -26))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, -18.2, -121.6))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, -11.8, -108.1))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, -93.2, -24.6))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, -116.3, -39))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, -55.6, 34.7))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, -69.9, 15.4))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, -124, -27.2))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, -37.4, 61.4))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, -36.3, 82.4))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, -21.6, 52.1))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, -33.5, 33.6))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, 28.6, 30.6))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, 40.7, -8.2))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, 47.4, -21.5))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, 63.2, -22.1))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, 59.7, -42.8))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, 72.7, -107.1))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, 52.7, -80.8))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, 62.3, 35.7))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), banca->getSphere(radiobancas, 99.4, 6.69))) {
			camara->posCam = camara->posCamPast;
		}

		//Lamparas
		float rLamparas = 6;

		
		if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -55, 110))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -35, 130))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -75, 123))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -95, 110))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -115, 130))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -125, 110))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, 35, 95))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, 55, 74))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, 75, 95))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, 95, 92))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, 115, 123))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, 55, 117))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, 37, 25))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, 70, 32))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, 90, 8))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, 110, 22))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, 130, 0))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, 35, 0))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, 62, -13))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, 48, -33))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, 61, -53))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, 49, -73))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, 83, -93))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, 78, -113))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -30, 95))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -23, 65))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -47, 45))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -50, 0))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -45, 20))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -62, 20))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -85, -20))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -115, -22))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -125, -55))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -25, -15))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -30, -40))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -7, -60))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -20, -80))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -10, -100))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), lampara->getSphere(rLamparas, -10, -100))) {
			camara->posCam = camara->posCamPast;
		}

		//Botes de basura
		float botesBasura = 6;
		if (isPointInsideSphere(camara->getPos(), boteBasura->getSphere(botesBasura, 36.5, 3.5))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), boteBasura->getSphere(botesBasura, 27.5, 20.5))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), boteBasura->getSphere(botesBasura, 102.2, -78.5))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), boteBasura->getSphere(botesBasura, -33.4, 56.2))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), boteBasura->getSphere(botesBasura, -45.5, 2.25))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), boteBasura->getSphere(botesBasura, -20.5, -70.5))) {
			camara->posCam = camara->posCamPast;
		}


		//Mesa picnic
		float rMesaPicnic = 8;

		if (isPointInsideSphere(camara->getPos(), mesaPicnic->getSphere(rMesaPicnic, 80, -80))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), mesaPicnic->getSphere(rMesaPicnic, 100, -60))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), mesaPicnic->getSphere(rMesaPicnic, 80, -40))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), mesaPicnic->getSphere(rMesaPicnic, 80, -60))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), mesaPicnic->getSphere(rMesaPicnic, 105, -75))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), mesaPicnic->getSphere(rMesaPicnic, 110, -50))) {
			camara->posCam = camara->posCamPast;
		}

		//Puesto

		if (isPointInsideSphere(camara->getPos(), puesto->getSphere(11, 100, -90))) {
			camara->posCam = camara->posCamPast;
		}

		//Museo
		if (isPointInsideSphere(camara->getPos(), museo->getSphere(25, -0, 110))) {
			camara->posCam = camara->posCamPast;
		}

		//Estatuas
		if (isPointInsideSphere(camara->getPos(), zeus->getSphere(6, zeus->getPosX(), zeus->getPosZ()))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), discolombus->getSphere(6, discolombus->getPosX(), discolombus->getPosZ()))) {
			camara->posCam = camara->posCamPast;
		}
		if (isPointInsideSphere(camara->getPos(), venus->getSphere(6, venus->getPosX(), venus->getPosZ()))) {
			camara->posCam = camara->posCamPast;
		}

		}
#pragma endregion 
		//tiempo->DrawText(-0.95, 0.95, "Hola mundo xd", 0.015);

		swapChain->Present( 1, 0 );
	}
	
	bool isPointInsideSphere(float* point, float* sphere) {
		bool collition = false;

		float distance = sqrt((point[0] - sphere[0]) * (point[0] - sphere[0]) +
			(point[1] - sphere[1]) * (point[1] - sphere[1]));

		if (distance < sphere[2]) {
			collition = true;
		}

		else if (distance > 5) {
			effectDone = false;
		}

		return collition;
	}

	//Activa el alpha blend para dibujar con transparencias
	void TurnOnAlphaBlending()
	{
		float blendFactor[4];
		blendFactor[0] = 0.0f;
		blendFactor[1] = 0.0f;
		blendFactor[2] = 0.0f;
		blendFactor[3] = 0.0f;
		HRESULT result;

		D3D11_BLEND_DESC descABSD;
		ZeroMemory(&descABSD, sizeof(D3D11_BLEND_DESC));
		descABSD.RenderTarget[0].BlendEnable = TRUE;
		descABSD.RenderTarget[0].SrcBlend = D3D11_BLEND_ONE;
		descABSD.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
		descABSD.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
		descABSD.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
		descABSD.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
		descABSD.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
		descABSD.RenderTarget[0].RenderTargetWriteMask = 0x0f;

		result = d3dDevice->CreateBlendState(&descABSD, &alphaBlendState);
		if(FAILED(result))
		{
			MessageBox(0, L"Error", L"Error al crear el blend state", MB_OK);
			return;
		}

		d3dContext->OMSetBlendState(alphaBlendState, blendFactor, 0xffffffff);
	}

	//Regresa al blend normal(solido)
	void TurnOffAlphaBlending()
	{
		D3D11_BLEND_DESC descCBSD;
		ZeroMemory(&descCBSD, sizeof(D3D11_BLEND_DESC));
		descCBSD.RenderTarget[0].BlendEnable = FALSE;
		descCBSD.RenderTarget[0].SrcBlend = D3D11_BLEND_ONE;
		descCBSD.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
		descCBSD.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
		descCBSD.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
		descCBSD.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
		descCBSD.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
		descCBSD.RenderTarget[0].RenderTargetWriteMask = 0x0f;
		HRESULT result;

		result = d3dDevice->CreateBlendState(&descCBSD, &commonBlendState);
		if(FAILED(result))
		{
			MessageBox(0, L"Error", L"Error al crear el blend state", MB_OK);
			return;
		}

		d3dContext->OMSetBlendState(commonBlendState, NULL, 0xffffffff);
	}

	void TurnOnDepth()
	{
		D3D11_DEPTH_STENCIL_DESC descDSD;
		ZeroMemory(&descDSD, sizeof(descDSD));
		descDSD.DepthEnable = true;
		descDSD.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
		descDSD.DepthFunc = D3D11_COMPARISON_LESS;
		descDSD.StencilEnable=true;
		descDSD.StencilReadMask = 0xFF;
		descDSD.StencilWriteMask = 0xFF;
		descDSD.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
		descDSD.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_INCR;
		descDSD.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
		descDSD.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;
		descDSD.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
		descDSD.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_DECR;
		descDSD.BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
		descDSD.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

		d3dDevice->CreateDepthStencilState(&descDSD, &depthStencilState);
		
		d3dContext->OMSetDepthStencilState(depthStencilState, 1);
	}

	void TurnOffDepth()
	{
		D3D11_DEPTH_STENCIL_DESC descDDSD;
		ZeroMemory(&descDDSD, sizeof(descDDSD));
		descDDSD.DepthEnable = false;
		descDDSD.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
		descDDSD.DepthFunc = D3D11_COMPARISON_LESS;
		descDDSD.StencilEnable=true;
		descDDSD.StencilReadMask = 0xFF;
		descDDSD.StencilWriteMask = 0xFF;
		descDDSD.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
		descDDSD.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_INCR;
		descDDSD.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
		descDDSD.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;
		descDDSD.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
		descDDSD.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_DECR;
		descDDSD.BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
		descDDSD.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

		d3dDevice->CreateDepthStencilState(&descDDSD, &depthStencilDisabledState);
		d3dContext->OMSetDepthStencilState(depthStencilDisabledState, 1);
	}

	void billCargaFuego()
	{
		uv1[0].u = .125;
		uv2[0].u = .125;
		uv3[0].u = 0;
		uv4[0].u = 0;

		uv1[0].v = .25;
		uv2[0].v = 0;
		uv3[0].v = 0;
		uv4[0].v = .25;


		for (int j = 0; j < 8; j++) {
			uv1[j].u = uv1[0].u + (j * .125);
			uv2[j].u = uv2[0].u + (j * .125);
			uv3[j].u = uv3[0].u + (j * .125);
			uv4[j].u = uv4[0].u + (j * .125);

			uv1[j].v = .25;
			uv2[j].v = 0;
			uv3[j].v = 0;
			uv4[j].v = .25;
		}
		for (int j = 0; j < 8; j++) {
			uv1[j + 8].u = uv1[0].u + (j * .125);
			uv2[j + 8].u = uv2[0].u + (j * .125);
			uv3[j + 8].u = uv3[0].u + (j * .125);
			uv4[j + 8].u = uv4[0].u + (j * .125);

			uv1[j + 8].v = .5;
			uv2[j + 8].v = .25;
			uv3[j + 8].v = .25;
			uv4[j + 8].v = .5;
		}

		for (int j = 0; j < 8; j++) {
			uv1[j + 16].u = uv1[0].u + (j * .125);
			uv2[j + 16].u = uv2[0].u + (j * .125);
			uv3[j + 16].u = uv3[0].u + (j * .125);
			uv4[j + 16].u = uv4[0].u + (j * .125);

			uv1[j + 16].v = .75;
			uv2[j + 16].v = .5;
			uv3[j + 16].v = .5;
			uv4[j + 16].v = .75;
		}

		for (int j = 0; j < 8; j++) {
			uv1[j + 24].u = uv1[0].u + (j * .125);
			uv2[j + 24].u = uv2[0].u + (j * .125);
			uv3[j + 24].u = uv3[0].u + (j * .125);
			uv4[j + 24].u = uv4[0].u + (j * .125);

			uv1[j + 24].v = 1;
			uv2[j + 24].v = .75;
			uv3[j + 24].v = .75;
			uv4[j + 24].v = 1;
		}
	}

	void pintar() {

		Contador++;

		if (Contador % 20 == 0)
		{

			if (ContFramesMañana != 0 && ContFramesTarde != 0 && ContFramesNoche != 0) //cuenta cuantas horas para que sea tarde
			{
				ContFramesMañana--;
				contadorGLSL++;
			}

			if (ContFramesTarde != 0 && ContFramesMañana == 0 && ContFramesNoche != 0)//cuenta cuantas horas para que sea noche
			{
				ContFramesTarde--;
				contadorGLSL++;
			}

			if (ContFramesMañana == 0 && ContFramesTarde == 0 && ContFramesNoche != 0)//cuenta cuantas horas para que sea dia
			{
				ContFramesNoche--;
				contadorGLSL++;
			}

			if (ContFramesNoche == 0)
			{
				ContFramesMañana = 80;
				ContFramesNoche = 40;
				ContFramesTarde = 80;
				contadorGLSL = 0;
			}
		}

		if (angle < 180.0f)
		{
			if (angle > 40.0f && angle < 140.0f)
				angle += 0.005f;
			else
			{
				angle += 0.010f;
			}
		}

		if (angle >= 180.0f)
			angle += 0.030f;


		if (angle >= 360.0f)
			angle = 0.0f;

		//angulos de iluminacion
		luzy = sin((angle * 41.2723) * PI / 180) * 350;
		luzx = 0;
		luzz = cos((angle * 41.2723) * PI / 180) * 350;

		dirluz.x = luzx;
		dirluz.y = luzy;
		dirluz.z = luzz;

		skydome->Update(camara->vista, camara->proyeccion);
		TurnOffDepth();
		skydome->Render(camara->posCam, contadorGLSL);
		TurnOnDepth();
	}
};
#endif