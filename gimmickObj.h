#pragma once
#include "obj.h"

const int MAX_GIMMICK = 10;

struct GimmickObj {
    Obj obj;
    bool isActive;
    int moveDir;
};

void InitGimmickObjs(GimmickObj gimmickObjs[]);
void UpdateGimmickObjs(GimmickObj gimmickObjs[], Obj& player);
void RenderGimmickObjs(GimmickObj gimmickObjs[], Vector2* scroll);
bool CheckGimmickCollision(GimmickObj& gimmick, Obj& player, Vector2& collisionNormal);
void NormalizeVector(Vector2& vector);
void ReflectPlayer(Obj& player, Vector2& normal);
