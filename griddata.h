#ifndef GRIDDATA_H
#define GRIDDATA_H

#include <QObject>
#include <QBitArray>

class GridData : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool correct READ correct NOTIFY correctChanged)
    Q_PROPERTY(int GameWidth READ GameWidth WRITE setGameWidth NOTIFY GameWidthChanged)
    Q_PROPERTY(int GameHeight READ GameHeight WRITE setGameHeight NOTIFY GameHeightChanged)

    public:
        explicit GridData(QObject *parent = 0);

        bool correct() const {return _correct;}
        int GameWidth() const {return width;}
        int GameHeight() const {return height;}

        bool valueAt(int x, int y) const {return checked.at(index(x, y));}
        bool safeValueAt(int x, int y) const {if (isInBoundaries(x, y)) return false; else return valueAt(x, y);}



    signals:

        void checkedChanged();
        void resultChanged();

        void correctChanged();

        void GameWidthChanged();
        void GameHeightChanged();

    public slots:
        void setGameWidth(int w) {width = w;}
        void setGameHeight(int h) {height = h;}

        void computeResult();
        void setValue(int x, int y, bool value) {if (!isInBoundaries(x, y)) return; int i = index(x, y); checked[i] = value; emit checkedChanged();}
        void switchValue(int x, int y) {setValue(x, y, !valueAt(x, y));}




    private:
        QBitArray checked;
        QBitArray result;
        bool _correct;
        int width;
        int height;

        int index(int x, int y) const {return x + y * width;}
        bool isInBoundaries(int x, int y) const {if (x < 0 || y < 0 || x >= width || y >= height) return false; else return true;}


};

#endif // GRIDDATA_H
