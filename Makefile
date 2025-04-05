teilpath=./src
teillibpath=teil.a

build:
	echo ${teilpath}
	gcc -I ${teilpath} -c \
		${teilpath}/teil/model/bayes/gaussiannb.c \
		${teilpath}/teil/model/pca/pca.c \
		${teilpath}/teil/model/tree/tree.c \
		${teilpath}/teil/model/svm/svc.c \
		${teilpath}/teil/model/svm/svr.c \
		${teilpath}/teil/model/neural_network/mlpc.c \
		${teilpath}/teil/model/neural_network/mlpr.c \
		${teilpath}/teil/model/neural_network/activation.c \
		${teilpath}/teil/model/neural_network/neural_utils.c \
		${teilpath}/teil/model/preprocessing/kernel.c \
		${teilpath}/teil/data/homology/zero_dimension.c \
		${teilpath}/teil/metrics/distance.c  \
	-lm
	ar ruv teil.a *.o
	ranlib teil.a


compile:
	gcc -I ${teilpath} *.c -L ${teillibpath} -lm 
