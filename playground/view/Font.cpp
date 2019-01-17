#include"playground/view/Font.h"
#include"playground/util/rectutil.h"
Font::FontItem::FontItem(){}

Font::FontItem::FontItem(Character c, Rect r) {
	Font::FontItem::character = c;
	Font::FontItem::rect = r;
}

Font::Font() {

}

Font::Font(vec2 p, float s, string c) {
	base.x = p.x;
	base.y = p.y;
	base.w = s;
	base.h = s;
	content = c;
}

void Font::Init(map<GLchar, Character>& characters) {
	int count = content.size();
	Rect child = base;
	child.w = 0;
	for (int i = 0; i < count; i++) {
		char c = content[i];
		Character character = characters[c];
		float blank = 0;
		if (c == ' ') {
			blank = 10;
		}
		child = CreateChildRect(character, Rect(child.x + child.w+interval+ blank, base.y, base.w, base.h));
		childs.push_back(FontItem(character, child));
	}
}

void Font::CreateAllChilds(map<GLchar, Character>& characters) {
	int count = content.size();
	for (int i = 0; i < count; i++) {
		char c = content[i];
		Character character= characters[c];
		Rect child = CreateChildRect(character, Rect(base.x+base.w*i, base.y, base.w, base.h));
		childs.push_back(FontItem(character,child));
	}
}

Rect Font::CreateChildRect(Character& character, Rect origin) {
	Rect result;
	origin.Process();
	//Point lb = ToPos(origin.bottomLeft);
	//Point opengllt;
	result.x = origin.bottomLeft.x + character.Bearing.x;
	result.y = origin.bottomLeft.y - character.Bearing.y;
	//Point rectlt = ToRectPos(opengllt);
	//result.x = rectlt.x;
	//result.y = rectlt.y;
	vec2 rectsize = (vec2(character.size.x,character.size.y));
	result.h = rectsize.y;
	result.w = rectsize.x;
	return result;
}