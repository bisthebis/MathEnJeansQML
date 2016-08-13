#include "griddata.h"

GridData::GridData(QObject *parent) : QObject(parent)
{

}

void GridData::computeResult()
{
    bool isCorrect = true; //Unless a false value is found
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            bool newValue = valueAt(x, y)
                          ^ safeValueAt(x - 1, y)
                          ^ safeValueAt(x + 1, y)
                          ^ safeValueAt(x, y - 1)
                          ^ safeValueAt(x, y + 1);

            isCorrect &= newValue;
        }
    }

    emit resultChanged();
    if (isCorrect != _correct)
    {
        _correct = isCorrect;
        emit correctChanged();
    }

}
