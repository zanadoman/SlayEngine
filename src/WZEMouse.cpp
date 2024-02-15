#include "WizardEngine.hpp"

using namespace neo;

namespace wze
{
    engine::mouse::mouse(engine* Engine) : Engine(Engine)
    {
        this->Sensitivity = 1;
        this->X = 0;
        this->Y = 0;
        this->MotionX = 0;
        this->MotionY = 0;
        this->Mode = false;
        this->CursorTextureID = 0;
    }

    double engine::mouse::GetSensitivity()
    {
        return this->Sensitivity;
    }

    double engine::mouse::SetSensitivity(double Sensitivity)
    {
        if (Sensitivity != Sensitivity)
        {
            printf("wze::engine.mouse.SetSensitivity(): Sensitivity must not be NaN\nParams: Sensitivity: %lf\n", Sensitivity);
            exit(1);
        }

        return this->Sensitivity = Sensitivity;
    }

    double engine::mouse::GetX(double Layer)
    {
        double cache;

        if (Layer != Layer)
        {
            printf("wze::engine.mouse.GetX(): Layer must not be NaN\nParams: Layer: %lf\n", Layer);
            exit(1);
        }
        if (Layer < 0)
        {
            printf("wze::engine.mouse.GetX(): Layer must not be less than 0\nParams: Layer: %lf\n", Layer);
            exit(1);
        }

        if (this->Mode)
        {
            return 0;
        }

        if (Layer == 0)
        {
            return this->X;
        }
        
        cache = this->Engine->Camera.Zoom * Layer;
        return this->X / cache + this->Engine->Camera.OriginX + this->Engine->Camera.OffsetX / cache;
    }

    double engine::mouse::GetY(double Layer)
    {
        double cache;

        if (Layer != Layer)
        {
            printf("wze::engine.mouse.GetY(): Layer must not be NaN\nParams: Layer: %lf\n", Layer);
            exit(1);
        }
        if (Layer < 0)
        {
            printf("wze::engine.mouse.GetY(): Layer must not be less than 0\nParams: Layer: %lf\n", Layer);
            exit(1);
        }

        if (this->Mode)
        {
            return 0;
        }

        if (Layer == 0)
        {
            return this->Y;
        }
        
        cache = this->Engine->Camera.Zoom * Layer;
        return this->Y / cache + this->Engine->Camera.OriginY + this->Engine->Camera.OffsetY / cache;
    }

    double engine::mouse::GetMotionX()
    {
        return this->MotionX;
    }

    double engine::mouse::GetMotionY()
    {
        return this->MotionY;
    }

    bool engine::mouse::IsAbsolute()
    {
        return !this->Mode;
    }

    bool engine::mouse::SetAbsolute()
    {
        SDL_SetRelativeMouseMode(SDL_FALSE);

        return !(this->Mode = false);
    }

    bool engine::mouse::IsRelative()
    {
        return this->Mode;
    }

    bool engine::mouse::SetRelative()
    {
        SDL_SetRelativeMouseMode(SDL_TRUE);

        return this->Mode = true;
    }

    uint64 engine::mouse::GetCursorTextureID()
    {
        return this->CursorTextureID;
    }

    uint64 engine::mouse::SetCursorTextureID(uint64 CursorTextureID)
    {
        if (CursorTextureID == 0)
        {
            printf("wze::engine.mouse.SetCursorTextureID(): Illegal use of NULL CursorTexture\nParams: CursorTextureID: %lld\n", CursorTextureID);
            exit(1);
        }
        if (this->Engine->Assets.CursorTextures.Length() <= CursorTextureID || this->Engine->Assets.CursorTextures[CursorTextureID] == NULL)
        {
            printf("wze::engine.mouse.SetCursorTextureID(): CursorTexture does not exist\nParams: CursorTextureID: %lld\n", CursorTextureID);
            exit(1);
        }

        SDL_SetCursor(this->Engine->Assets.CursorTextures[CursorTextureID]);

        return this->CursorTextureID = CursorTextureID;
    }

    uint8 engine::mouse::Update()
    {
        sint32 x, y;

        SDL_GetRelativeMouseState(&x, &y);
        this->MotionX = x * this->Sensitivity;
        this->MotionY = -(y * this->Sensitivity);

        for (uint64 i = 0; i < this->Engine->EventQueue.Length(); i++)
        {
            if (this->Engine->EventQueue[i].type == SDL_MOUSEMOTION)
            {
                this->X = this->Engine->EventQueue[i].motion.x;
                if (this->X < 0)
                {
                    this->X = 0;
                }
                else if (this->Engine->Window.Width <= this->X)
                {
                    this->X = this->Engine->Window.Width - 1;
                }

                this->Y = -(this->Engine->EventQueue[i].motion.y - this->Engine->Render.RenderHeight);
                if (this->Y < 0)
                {
                    this->Y = 0;
                }
                else if (this->Engine->Window.Height <= this->Y)
                {
                    this->Y = this->Engine->Window.Height - 1;
                }
            }
        }

        return 0;
    }
}