#include "griddata.h"

GridData::GridData(QObject *parent, const int w, const int h) : QObject(parent), width(w), height(h)
{
    //Init BitArrays before connecting
    setGameWidth(w);
    setGameHeight(h);
    connect(this, &GridData::checkedChanged, this, &GridData::computeResult);

}

void GridData::resizeArrays(const int w, const int h)
{
    checked.fill(false, w*h);
    result.fill(false, w*h);
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
            result[index(x, y)] = newValue;

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

void GridData::setValue(int x, int y, bool value)
{
    if (!isInBoundaries(x, y))
        return;

    int i = index(x, y);
    checked[i] = value;
    emit checkedChanged();
}
