obj-m := busdriverclea.o
KDIR := /lib/modules/4.15.0-66-generic/build
all:
	make -C $(KDIR) M=$(PWD) modules 
clean:
	rm -f *.ko *.o *.mod.o *.mod.c *.symvers *.bak *.order *cmd
