#include "gimmickObj.h"
#include "obj.h"
#include <Novice.h>

const int BOX_COUNT = 3;

void InitGimmickObjs(GimmickObj gimmickObjs[]) {
    for (int i = 0; i < BOX_COUNT; i++) {
        gimmickObjs[i].obj.pos.x = (float)(300 + i * 200);
        gimmickObjs[i].obj.pos.y = 400.0f;
        gimmickObjs[i].obj.radius = 20.0f;
        gimmickObjs[i].isActive = true;
        gimmickObjs[i].moveDir = 1;
    }
}

void UpdateGimmickObjs(GimmickObj gimmickObjs[], Obj& player) {
    for (int i = 0; i < BOX_COUNT; i++) {
        if (gimmickObjs[i].isActive) {
            
            gimmickObjs[i].obj.pos.y += 2.0f * gimmickObjs[i].moveDir;
            if (gimmickObjs[i].obj.pos.y >= 450.0f || gimmickObjs[i].obj.pos.y <= 350.0f) {
                gimmickObjs[i].moveDir *= -1;
            }

            if (CheckGimmickCollision(gimmickObjs[i], player)) {
               
                Vector2 collisionNormal = {
                    player.pos.x - gimmickObjs[i].obj.pos.x,
                    player.pos.y - gimmickObjs[i].obj.pos.y
                };
                NormalizeVector(collisionNormal);
                ReflectPlayer(player, collisionNormal); 
            }
        }
    }
}

void RenderGimmickObjs(GimmickObj gimmickObjs[], Vector2* scroll) {
    for (int i = 0; i < BOX_COUNT; i++) {
        if (gimmickObjs[i].isActive) {
            Novice::DrawBox(
                (int)(gimmickObjs[i].obj.pos.x - scroll->x),
                (int)(gimmickObjs[i].obj.pos.y - scroll->y),
                40, 40, 0, 0xFFFF00FF, kFillModeSolid
            );
        }
    }
}

bool CheckGimmickCollision(GimmickObj& gimmick, Obj& player) {
    float dx = player.pos.x - gimmick.obj.pos.x;
    float dy = player.pos.y - gimmick.obj.pos.y;
    float distance = sqrtf(dx * dx + dy * dy);
    return distance < (player.radius + gimmick.obj.radius);
}


void NormalizeVector(Vector2& vector) {
    float length = sqrtf(vector.x * vector.x + vector.y * vector.y);
    if (length != 0) {
        vector.x /= length;
        vector.y /= length;
    }
}

void ReflectPlayer(Obj& player, Vector2& normal) {
  
    Vector2 velocity = { cosf(player.angle) * player.velocity.x, sinf(player.angle) * player.velocity.y };

    
    NormalizeVector(normal);

    
    float dotProduct = velocity.x * normal.x + velocity.y * normal.y;

    
    velocity.x -= 2 * dotProduct * normal.x;
    velocity.y -= 2 * dotProduct * normal.y;

    
    player.angle = atan2f(velocity.y, velocity.x);

    
    player.pos.x += velocity.x;
    player.pos.y += velocity.y;
}

