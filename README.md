# TCM
This is the implementation of a table-based higher order masking scheme againt the horizontal SCA attacks. This is only for performance analysis. If for secure application, one needs to check very carfully the assembly code of this implementation. 

The files named aes_ltable are our countermeasure (TCM scheme). The files named aes_htable, aes_rp10 and aes_rp are corresponding to the countermeasures proposed in [1,2,3].

[1]Jean-Sébastien Coron. Higher order masking of look-up tables. In Annual International Conference on the Theory and Applications of Cryptographic Techniques, pages 441–458. Springer, 2014.

[2]Matthieu Rivain and Emmanuel Prouff. Provably secure higher-order masking of AES. In International Workshop on Cryptographic Hardware and Embedded Systems, pages 413–427. Springer, 2010.

[3]Alberto Battistello, Jean-Sébastien Coron, Emmanuel Prouff, and Rina Zeitoun. Horizontal side-channel attacks and countermeasures on the isw masking scheme. In International Conference on Cryptographic Hardware and Embedded Systems, pages 23–39. Springer, 2016.
