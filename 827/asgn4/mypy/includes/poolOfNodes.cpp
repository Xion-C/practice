#include "node.h"
#include "poolOfNodes.h"

PoolOfNodes& PoolOfNodes::getInstance() {
  static PoolOfNodes pool;
  return pool;
}

void PoolOfNodes::drainThePool() {
    // std::cout << "poolsize " << nodePool.size() << std::endl;
    for ( const Node* node : nodePool ) {
        if (node == NULL) {
            std::cout << "-- can't not pointer NULL" << std::endl;
            continue;
        }
        delete node; //can not be "delete [] node" here
    }
}
