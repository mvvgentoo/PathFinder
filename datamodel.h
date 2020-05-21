#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <unitypes.h>
#include <string.h>

enum class ErrorCode: uint8_t
{
  Success,
  Fail,
  Count
};

template <int value>
class Serializable
{
  public:
    virtual ~Serializable() = 0;
    virtual ErrorCode Serialize(const std::string& objName) = 0;
    virtual ErrorCode DeSerialize(const std::string& objName) = 0;

    static decltype(value) GetVersion() {return value;}
};

#define DATA_SCHEMA(name, version) \
  struct name : public Serializable<version>

#define DATA_WRAP(data) \
  union data_##union \
  {\
   data;\
   char rawData[sizeof(data)];\
  }

DATA_SCHEMA(AStarData, 1)
{
  AStarData();
  ~AStarData();
  virtual ErrorCode Serialize(const std::string& objName) override;
  virtual ErrorCode DeSerialize(const std::string& objName) override;

  //Data
  struct CellData
  {
    size_t cellIndex;
    size_t heuristic;
    size_t costFunction;
    size_t parentIndex;
    size_t totalCostFunction;
  };

  std::vector<CellData> cells;
};

class AStarDataModel
{        
  public:
    AStarDataModel();


  private:
    AStarData d;

};

#endif // DATAMODEL_H
