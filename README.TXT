A bunch of converters/filters for SDR sample data.

sc8 indicates samples in a format consisting of 8 bit signed I/Q data pairs.
sc16 indicates samples in a format consisting of 16 bit signed I/Q data pairs (lower endian).

fl indicates samples in a format consisting of float I/Q data pairs.

The mul tool multiplicates the samples by a given (arg #1) float factor.
The drop tool drops n-1 samples (arg #1) after outputting 1 sample.
The fsover4 shifts frequencies by fs/4 to the left (lower freq). Beware that the lower fs/4 part becomes the new higher fs/4 part.
