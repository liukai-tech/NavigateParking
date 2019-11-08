#include "randomparking.h"
#include "parkingpositioninfo.h"
#include "car.h"
#include <QRandomGenerator>

QSharedPointer<RandomParking> RandomParking::m_Ins;

RandomParking* RandomParking::GetIns()
{
    if (nullptr == m_Ins.get())
    {
        m_Ins.reset(new RandomParking());
    }
    return m_Ins.get();
}

RandomParking::RandomParking()
{

}

RandomParking::~RandomParking()
{

}

void RandomParking::InitParking()
{
    const QVector<QSharedPointer<ParkingPositionInfo>>& all = ParkingPositions::GetIns()->GetAllPositions();
    foreach (const QSharedPointer<ParkingPositionInfo>& iter, all)
    {
        int randomRate = QRandomGenerator::global()->bounded(0,100);
        if(randomRate < 80)
        {
            iter.get()->Use();
        }
    }

    Car::GetIns()->RandomPosition();
}
