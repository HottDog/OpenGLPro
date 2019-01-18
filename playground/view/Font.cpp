#include"playground/view/Font.h"
#include"playground/util/rectutil.h"
Font::FontItem::FontItem(){}

Font::FontItem::FontItem(Character c, Rect r) {
	Font::FontItem::character = c;
	Font::FontItem::rect = r;
}

Font::Font() {

}

Font::Font(vec2 p, int s, string c) {
	base.x = p.x;
	base.y = p.y;
	base.w = s;
	base.h = s;
	content = c;
	size = s;
}

void Font::Init(map<GLchar, Character>& characters) {
	float scale = float(size / STANDARD_SIZE);
	blankInterval *= scale;
	interval *= scale;
	int count = content.size();
	Rect child = base;
	child.w = 0;
	float blank = 0;
	for (int i = 0; i < count; i++) {
		char c = content[i];
		Character character = characters[c];		
		if (c == ' ') {
			blank = blankInterval;
		}
		else {
			child = CreateChildRect(character, Rect(child.x + child.w + interval + blank, base.y, base.w, base.h), scale);
			childs.push_back(FontItem(character, child));
			blank = 0;
		}		
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

Rect Font::CreateChildRect(Character& character, Rect origin,float scale) {
	Rect result;
	origin.Process();
	//Point lb = ToPos(origin.bottomLeft);
	//Point opengllt;
	result.x = origin.bottomLeft.x + (character.Bearing.x *scale);
	result.y = origin.bottomLeft.y - (character.Bearing.y*scale);
	//Point rectlt = ToRectPos(opengllt);
	//result.x = rectlt.x;
	//result.y = rectlt.y;
	vec2 rectsize = (vec2(character.size.x,character.size.y))*scale;
	result.h = rectsize.y;
	result.w = rectsize.x;
	return result;
}