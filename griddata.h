#ifndef GRIDDATA_H
#define GRIDDATA_H

#include <QObject>
#include <QVector>

#include "globals.h"

class QTextStream;

class GridData : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool correct READ correct NOTIFY correctChanged)
    Q_PROPERTY(int GameWidth READ GameWidth WRITE setGameWidth NOTIFY GameWidthChanged)
    Q_PROPERTY(int GameHeight READ GameHeight WRITE setGameHeight NOTIFY GameHeightChanged)

    public:
        explicit GridData(QObject *parent = nullptr, const int w = 3, const int h = 3);
        explicit GridData(const GridData&) = default;

        bool correct() const {return _correct;}
        int GameWidth() const {return width;}
        int GameHeight() const {return height;}

        bool valueAt(int x, int y) const {return checked.at(index(x, y));}
        bool resultAt(int x, int y) const {return result.at(index(x, y));}
        Q_INVOKABLE bool safeValueAt(int x, int y) const {if (!isInBoundaries(x, y)) return false; else return valueAt(x, y);}
        Q_INVOKABLE bool safeResultAt(int x, int y) const {if (!isInBoundaries(x, y)) return false; else return resultAt(x, y);}

        Q_INVOKABLE int index(int x, int y) const {return x + y * width;}



    signals:

        void checkedChanged();
        void resultChanged();

        void correctChanged();

        void GameWidthChanged();
        void GameHeightChanged();

    public slots:
        void setGameWidth(int w) {width = w; resizeArrays(w, height); emit GameWidthChanged();}
        void setGameHeight(int h) {height = h; resizeArrays(width, h); emit GameHeightChanged();}
        void restart();

        void computeResult();
        void setValue(int x, int y, bool value);
        void switchValue(int x, int y) {setValue(x, y, !safeValueAt(x, y));}

        void complete();
        void copyFirstLine(const QVector<bool>& src);

        void print(QTextStream& destination) const;
        void printToStdout() const {print(out());}


    private:
        void resizeArrays(const int w, const int h);
        void completeRow(int y); // PRE : row != 0, checked is empty in row, row -1 is completed. POST : only called row is changed in checked
                                 // User MUST emit checkedChanged()
    private:

        QVector<bool> checked;
        QVector<bool> result;
        bool _correct = false;
        int width = 0;
        int height = 0;


        bool isInBoundaries(int x, int y) const {if (x < 0 || y < 0 || x >= width || y >= height) return false; else return true;}


};

#endif // GRIDDATA_H
