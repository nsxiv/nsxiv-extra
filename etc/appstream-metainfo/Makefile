install-metainfo:
	@echo "INSTALL page.codeberg.nsxiv.nsxiv.metainfo.xml"
	mkdir -p $(DESTDIR)$(PREFIX)/share/metainfo
	cp page.codeberg.nsxiv.nsxiv.metainfo.xml $(DESTDIR)$(PREFIX)/share/metainfo
	chmod 644 $(DESTDIR)$(PREFIX)/share/metainfo/page.codeberg.nsxiv.nsxiv.metainfo.xml

uninstall-metainfo:
	@echo "REMOVE page.codeberg.nsxiv.nsxiv.metainfo.xml"
	rm -f $(DESTDIR)$(PREFIX)/share/metainfo/page.codeberg.nsxiv.nsxiv.metainfo.xml
