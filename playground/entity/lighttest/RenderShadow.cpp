#include"RenderShadow.h"
#include<assimp/Importer.hpp>
#include<assimp/scene.h>
#include<assimp/postprocess.h>
#include<iostream>
using namespace std;
using namespace Assimp;
RenderShadow::RenderShadow()
{

}

bool RenderShadow::Start()
{
	NormalTask::Start();
	InitRectOG(ogObj);
	return true;
}

bool RenderShadow::Draw()
{
	NormalTask::Draw();
	return true;
}

bool RenderShadow::Destroy()
{
	NormalTask::Destroy();
	return true;
}

void RenderShadow::LoadModel()
{
	Importer importer;
	char * path = "";
	const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);
	if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
	{
		cout << "ERROR::ASSIMP::"<<importer.GetErrorString()<<endl;
		return;
	}

}