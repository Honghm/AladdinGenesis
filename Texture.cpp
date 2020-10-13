#include "Texture.h"


CTexture * CTexture::_instance = NULL;

CTexture * CTexture::GetInstance()
{
	if (_instance == NULL)
	{
		_instance = new CTexture();
	}
	return _instance;
}

CTexture::CTexture()
{
	LoadTexTure();
}

void CTexture::Add(Type id, LPCSTR texturePath, D3DCOLOR transparentColor)
{
	D3DXIMAGE_INFO info;
	HRESULT result = D3DXGetImageInfoFromFile(texturePath, &info);
	if (result != D3D_OK)
	{
		//DebugOut(L"Loi Load Texture");
		return;

	}
	LPDIRECT3DDEVICE9 d3ddv = CGame::GetInstance()->GetDirect3dDevice();
	LPDIRECT3DTEXTURE9 texture;
	result = D3DXCreateTextureFromFileEx(
		d3ddv,
		texturePath,
		info.Width,
		info.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		transparentColor,
		&info,
		NULL,
		&texture
	);
	if (result != D3D_OK)
	{
		return;
	}
	this->texture[id] = texture;
	this->image_info[id] = info;

}

void CTexture::LoadTexTure()
{
	// Aladin Texture
	Add(Type::ALADIN, "Resources/Aladin/Aladdin4.png", D3DCOLOR_XRGB(255, 0, 255));
	Add(Type::ALADIN2, "Resources/Aladin/Aladdin2.png", D3DCOLOR_RGBA(106, 148,189, 1));
	Add(Type::ALADIN3, "Resources/Aladin/Aladdin5.png", D3DCOLOR_RGBA(106, 148, 189, 1));
	

	//Map
	Add(Type::Map1, "Resources/Map/map1_tileSet.png");
	Add(Type::Map2, "Resources/Map/map2_tileSet.png");
	Add(Type::Map3, "Resources/Map/map3_tileSet.png");
	Add(Type::Map4, "Resources/Map/map4_tileSet.png");
	Add(Type::Map5, "Resources/Map/map5_tileSet.png");
	Add(Type::Map6, "Resources/Map/map6_tileSet.png");
	Add(Type::Map7, "Resources/Map/map7_tileSet.png");
	Add(Type::Map8, "Resources/Map/map8_tileSet.png");
	Add(Type::Map9, "Resources/Map/map9_tileSet.png");
	Add(Type::Map10, "Resources/Map/map10_tileSet.png");
	
	

	//Bbox
	Add(Type::BOX, "Resources/Object/bbox.png");

	//Enemy
	
}

LPDIRECT3DTEXTURE9 CTexture::Get(Type id)
{
	return this->texture[id];
}

D3DXIMAGE_INFO CTexture::GetImageInfo(Type id)
{
	return this->image_info[id];
}



CTexture::~CTexture()
{
}
