EXTRA_DIST = linux-atm.spec.in \
	ANS/127.0.0 ANS/atm-reverse ANS/e164_cc ANS/pdf2e164_cc.pl ANS/resolv.conf \
	ANS/192.168.27 ANS/bind-498-REL.patch ANS/hosts2ans.pl ANS/README ANS/atm \
	ANS/named.conf ANS/README.DNS \
	pca200e.data pca200e_ecd.data sba200e_ecd.data

BUILT_SOURCES = pca200e.bin pca200e_ecd.bin2 sba200e_ecd.bin2
CLEANFILES = pca200e.bin pca200e_ecd.bin2 sba200e_ecd.bin2

OBJCOPY = objcopy

install-exec-hook:
	$(MKDIR_P) $(DESTDIR)/lib/firmware
	$(INSTALL_DATA) $(srcdir)/pca200e.bin $(DESTDIR)/lib/firmware
	$(INSTALL_DATA) $(srcdir)/pca200e_ecd.bin2 $(DESTDIR)/lib/firmware
	$(INSTALL_DATA) $(srcdir)/sba200e_ecd.bin2 $(DESTDIR)/lib/firmware

%.bin %.bin2: %.data
	$(OBJCOPY) -Iihex $< -Obinary $@.gz
	gzip -n -df $@.gz


