#ifndef DETECTHEADRESULT_H
#define DETECTHEADRESULT_H
#include <QMetaType>
class Detectheadresult
{
public:
    Detectheadresult();
    int getCenterY() const;
    void setCenterY(int value);

    int getCount() const;
    void setCount(int value);

private:
    int count;
    int centerY;
};
Q_DECLARE_METATYPE(Detectheadresult)
#endif // DETECTHEADRESULT_H
