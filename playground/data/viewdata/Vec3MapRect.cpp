#include"Vec3MapRect.h"
Vec3MapRect::Vec3MapRect(vec3 c)
{
	color = c;

}

bool HasColor(vector<Vec3MapRect>& datas, vec3 c)
{
	//迭代器遍历
	for (vector<Vec3MapRect>::iterator it = datas.begin(); it != datas.end(); it++)
	{
		if ((*it).color == c)
		{
			return true;
		}

	}
	return false;
}

Vec3MapRect* Find(vector<Vec3MapRect>& datas, vec3 c)
{
	//迭代器遍历
	for (int i = 0; i < datas.size(); i++)
	{
		if (datas[i].color == c)
		{
			return &datas[i];
		}
	}
}

void InsertRect(vector<Vec3MapRect>& datas, vec3 c, Rect r)
{
	if (HasColor(datas, c))
	{
		Find(datas, c)->rects.push_back(r);
	}
	else
	{
		Vec3MapRect item(c);
		item.rects.push_back(r);
		datas.push_back(item);
	}
}