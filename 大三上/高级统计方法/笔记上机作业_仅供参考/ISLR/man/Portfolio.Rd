\name{Portfolio}
\alias{Portfolio}
\docType{data}
\title{Portfolio Data
%%   ~~ data name/kind ... ~~
}
\description{A simple simulated data set containing 100 returns for each
  of two assets, X and Y. The data is used to estimate the optimal
  fraction to invest in each asset to minimize investment risk of the
  combined portfolio. One can then use the Bootstrap to estimate the
  standard error of this estimate.
%%  ~~ A concise (1-5 lines) description of the dataset. ~~
}
\usage{Portfolio}
\format{
  A data frame with 100 observations on the following 2 variables.
  \describe{
    \item{\code{X}}{Returns for Asset X}
    \item{\code{Y}}{Returns for Asset Y}
  }
}
\source{Simulated data
%%  ~~ reference to a publication or URL from which the data were obtained ~~
}
\references{
  James, G., Witten, D., Hastie, T., and Tibshirani, R. (2013)
  \emph{An Introduction to Statistical Learning with applications in R},
  \url{www.StatLearning.com},
  Springer-Verlag, New York
}
\examples{
summary(Portfolio)
attach(Portfolio)
plot(X,Y)
}
\keyword{datasets}
