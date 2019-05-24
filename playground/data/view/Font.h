#pragma once
#include"playground/data/view/rect.h"
#include<vector>
#include<string>
#include<map>
#include"common/opengltool.h"
using namespace std;
const float STANDARD_SIZE = 20.0f;
class Font {
public:
	

	struct FontItem {
	public:
		FontItem();
		FontItem(Character c, Rect r);
		Character character;
		Rect rect;
	};
	Font();
	Font(vec2 p, int s, string c);
	Rect base;
	string content;
	float interval = 3;    //���
	float blankInterval = 10;   //�ո���
	vec3 color = vec3(1,0,0);   //Ĭ���Ǻ�ɫ
	vector<FontItem> childs;
	int size = 20;

	void CreateAllChilds(map<GLchar, Character>& characters);
	void Init(map<GLchar, Character>& characters);
private:
	

	//@param 
	// origin ���½ǵ�����
	Rect CreateChildRect(Character& character,Rect origin,float scale = 1.0);
};