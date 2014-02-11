include /afs/.ir/users/p/u/pusiol/prototypes-vision-ai/trunk/SFU-TLD/ccv-unstable-Jan2012/cornlib/config.mk

#CC += -faddress-sanitizer -fno-omit-frame-pointer
LDFLAGS := -L /afs/.ir/users/p/u/pusiol/prototypes-vision-ai/trunk/SFU-TLD/ccv-unstable-Jan2012/cornlib   -lccv $(LDFLAGS)
CFLAGS := -O3 -Wall -I "/afs/.ir/users/p/u/pusiol/prototypes-vision-ai/trunk/SFU-TLD/ccv-unstable-Jan2012/cornlib" $(CFLAGS)

TARGETS = bbffmt msermatch siftmatch bbfcreate bbfdetect swtcreate swtdetect dpmcreate dpmdetect convert tld

all: libccv.a  $(TARGETS)

clean:
	${MAKE} clean -C ../lib ; rm -f *.o $(TARGETS)

$(TARGETS): %: %.o libccv.a
	$(CC) -o $@ $< $(LDFLAGS)

libccv.a:
	${MAKE} -C /afs/.ir/users/p/u/pusiol/prototypes-vision-ai/trunk/SFU-TLD/ccv-unstable-Jan2012/cornlib

%.o: %.c /afs/.ir/users/p/u/pusiol/prototypes-vision-ai/trunk/SFU-TLD/ccv-unstable-Jan2012/cornlib/ccv.h
	$(CC) $< -o $@ -c $(CFLAGS)
