#include "node.h"
#include "poolOfNodes.h"

PoolOfNodes& PoolOfNodes::getInstance() {
  static PoolOfNodes pool;
  return pool;
}

void PoolOfNodes::drainThePool() {
    //std::cout << "poolsize " << nodePool.size() << std::endl;
    for ( const Node* node : nodePool ) {
        delete [] node;
    }
}
