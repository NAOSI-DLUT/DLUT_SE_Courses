\name{Khan}
\alias{Khan}
\docType{data}
\title{Khan Gene Data
%%   ~~ data name/kind ... ~~
}
\description{The data consists of a
  number of tissue samples corresponding to four distinct types of small
  round blue cell tumors. For each tissue sample, 2308 gene expression measurements are available.
%%  ~~ A concise (1-5 lines) description of the dataset. ~~
}
\usage{Khan}
\format{
  The format is a list containing four components: \code{xtrain},
  \code{xtest}, \code{ytrain}, and \code{ytest}. \code{xtrain} contains
  the 2308 gene expression values for 63 subjects and \code{ytrain}
  records the corresponding tumor type. \code{ytrain} and \code{ytest}
  contain the corresponding testing sample information for a further 20 subjects.

}
\source{This data were originally reported in:

  Khan J, Wei J, Ringner M, Saal L, Ladanyi M, Westermann F, Berthold
  F, Schwab M, Antonescu C, Peterson C, and Meltzer P. Classification
  and diagnostic prediction of cancers using gene expression profiling
  and artificial neural networks. Nature Medicine, v.7, pp.673-679, 2001.

  The data were also used in:

  Tibshirani RJ, Hastie T, Narasimhan B, and G. Chu. Diagnosis of Multiple Cancer Types by
Shrunken Centroids of Gene Expression. Proceedings of the National Academy of
Sciences of the United States of America, v.99(10), pp.6567-6572, May
14, 2002.

%They are also available in the pamr package.
%%  ~~ reference to a publication or URL from which the data were obtained ~~
}
\references{
  James, G., Witten, D., Hastie, T., and Tibshirani, R. (2013)
  \emph{An Introduction to Statistical Learning with applications in R},
  \url{www.StatLearning.com},
  Springer-Verlag, New York
}
\examples{
table(Khan$ytrain)
table(Khan$ytest)
}
\keyword{datasets}
