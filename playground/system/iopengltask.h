#pragma once
__interface IOpenglTask
{
	bool Start();

	bool Update();

	bool Destroy();

	bool IsEnd();
};