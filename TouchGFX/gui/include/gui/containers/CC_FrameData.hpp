#ifndef CC_FRAMEDATA_HPP
#define CC_FRAMEDATA_HPP

#include <gui_generated/containers/CC_FrameDataBase.hpp>

class CC_FrameData : public CC_FrameDataBase
{
public:
    CC_FrameData();
    virtual ~CC_FrameData() {}

    virtual void initialize();
    void textArea_Name_setWildcard(const Unicode::UnicodeChar* value);
    void textArea_Value_Invalidate();
    int getTextArea_ValueBufferSize();
    touchgfx::Unicode::UnicodeChar* getTextArea_ValueBuffer();
    void box_Err_setColor(colortype color);
    void box_Err_setAlpha(uint8_t newAlpha);
protected:
};

#endif // CC_FRAMEDATA_HPP
