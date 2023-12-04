\name{NCI60}
\alias{NCI60}
\docType{data}
\title{NCI 60 Data
%%   ~~ data name/kind ... ~~
}
\description{NCI microarray data. The data contains expression levels on
  6830 genes from 64 cancer cell lines. Cancer type is also recorded.
%%  ~~ A concise (1-5 lines) description of the dataset. ~~
}
\usage{NCI60}
\format{
  The format is a list containing two elements: \code{data} and
  \code{labs}.

  \code{data} is a 64 by 6830 matrix of the expression values while
  \code{labs} is a vector listing the cancer types for the 64 cell lines.
}
\source{The data come from Ross et al. (Nat Genet., 2000). More information can be obtained at
  http://genome-www.stanford.edu/nci60/ 
%  http://www-stat.stanford.edu/~tibs/ElemStatLearn/
%%  ~~ reference to a publication or URL from which the data were obtained ~~
}
\references{
  James, G., Witten, D., Hastie, T., and Tibshirani, R. (2013)
  \emph{An Introduction to Statistical Learning with applications in R},
  \url{www.StatLearning.com},
  Springer-Verlag, New York
}
\examples{
table(NCI60$labs)
}
\keyword{datasets}
