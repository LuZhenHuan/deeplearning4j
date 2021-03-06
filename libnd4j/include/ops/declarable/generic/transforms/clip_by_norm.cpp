//
//  @author raver119@gmail.com
//

#include <op_boilerplate.h>
#if NOT_EXCLUDED(OP_clipbynorm)

#include <ops/declarable/CustomOperations.h>
#include<ops/declarable/helpers/transforms.h>

namespace nd4j {
namespace ops  {

    CONFIGURABLE_OP_IMPL(clipbynorm, 1, 1, true, 1, 0) {
        auto input = INPUT_VARIABLE(0);
        auto output = OUTPUT_VARIABLE(0);

        const T clipNorm = T_ARG(0);
        const bool isInplace = block.isInplace();

        helpers::clipByNorm(*input, *output, *block.getIArguments(), clipNorm, isInplace);

        return Status::OK();
    }


    CUSTOM_OP_IMPL(clipbynorm_bp, 2, 1, false, 1, 0) {
        auto input = INPUT_VARIABLE(0);
        auto epsNext = INPUT_VARIABLE(1);

        auto output = OUTPUT_VARIABLE(0);
        const T clipNorm = T_ARG(0);

        helpers::clipByNormBp(*input, *epsNext, *output, *block.getIArguments(), clipNorm);

        return Status::OK();
    }

    DECLARE_SHAPE_FN(clipbynorm_bp) {
        auto inShapeInfo = inputShape->at(0);

        Nd4jLong *newShape = nullptr;
        COPY_SHAPE(inShapeInfo, newShape);

        return SHAPELIST(newShape);
    }


}
}

#endif