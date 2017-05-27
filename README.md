# TCM
This is the implementation of a table-based higher order masking scheme againt the horizontal SCA attacks. This is only for performance analysis. If for secure application, one needs to check very carfully the assembly code of this implementation. 

The files named aes_ltable are our countermeasure. The files named aes_htable and aes_rp are corresponding to the countermeasures proposed in [1,2].

[1]Jean-Sébastien Coron. Higher order masking of look-up tables. In Annual International Conference on the Theory and Applications of Cryptographic Techniques, pages 441–458. Springer, 2014.

[2]Alberto Battistello, Jean-Sébastien Coron, Emmanuel Prouff, and Rina Zeitoun. Horizontal side-channel attacks and countermeasures on the isw masking scheme. In International Conference on Cryptographic Hardware and Embedded Systems, pages 23–39. Springer, 2016.
