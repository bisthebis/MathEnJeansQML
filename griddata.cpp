#include "griddata.h"
#include <QCoreApplication>

GridData::GridData(QObject *parent, const int w, const int h) : QObject(parent), width(w), height(h)
{
    //Init BitArrays before connecting
    setGameWidth(w);
    setGameHeight(h);
    connect(this, &GridData::checkedChanged, this, &GridData::computeResult);

}

void GridData::resizeArrays(const int w, const int h)
{
    const int size = w*h;
    checked.reserve(size);
    checked.clear();
    result.reserve(size);
    result.clear();
    for (int i = 0; i < size; ++i)
    {
        checked.push_back(false);
        result.push_back(false);
    }
    //checked.fill(false, w*h);
    //result.fill(false, w*h);
}
void GridData::restart()
{
    const int size = width*height;
    checked.reserve(size);
    checked.clear();
    for (int i = 0; i < size; ++i)
    {
        checked.push_back(false);
    }
    emit checkedChanged();
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

void GridData::copyFirstLine(const QVector<bool>& src)
{
    if (src.size() < width)
        qApp->quit(); //Fatal error

    const int size = width*height;
    checked.reserve(size);
    checked.clear();
    for (int i = 0; i < size; ++i)
        checked.push_back(false);

    //checked.fill(false, size);
    for (int i = 0; i < width; ++i)
    {
        checked[i] = src.at(i);
    }
    emit checkedChanged();
}

//Solving slots
void GridData::completeRow(int y)
{
    //Safety
    //Q_ASSERT(y != 0);
    for (int x = 0; x < width; ++x)
    {
        int i = index(x, y);
        //Q_ASSERT(!checked[i]);
        checked[i] = !result[i-width];


    }


}


void GridData::complete()
{
    //Cleanup all the lines;
    for (int i = width; i < checked.size(); ++i)
    {
        checked[i] = false;
    }
    //Ensure 2nd line is correct;
    computeResult();

    for (int y = 1; y < height; y++)
    {
        completeRow(y);
        computeResult();

    }


}
