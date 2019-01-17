#pragma once
#include"playground/shape/rect.h"
#include<vector>
#include<string>
#include<map>
#include"common/opengltool.h"
using namespace std;
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
	Font(vec2 p, float s, string c);
	Rect base;
	string content;
	float interval = 3;    //间距
	vec3 color = vec3(1,0,0);   //默认是红色
	vector<FontItem> childs;

	void CreateAllChilds(map<GLchar, Character>& characters);
	void Init(map<GLchar, Character>& characters);
private:
	

	//@param 
	// origin 左下角点坐标
	Rect CreateChildRect(Character& character,Rect origin);
};