\name{Smarket}
\alias{Smarket}
\docType{data}
\title{S&P Stock Market Data
%%   ~~ data name/kind ... ~~
}
\description{Daily percentage returns for the S&P 500 stock index
  between 2001 and 2005. 
%%  ~~ A concise (1-5 lines) description of the dataset. ~~
}
\usage{Smarket}
\format{
  A data frame with 1250 observations on the following 9 variables.
  \describe{
    \item{\code{Year}}{The year that the observation was recorded}
    \item{\code{Lag1}}{Percentage return for previous day}
    \item{\code{Lag2}}{Percentage return for 2 days previous}
    \item{\code{Lag3}}{Percentage return for 3 days previous}
    \item{\code{Lag4}}{Percentage return for 4 days previous}
    \item{\code{Lag5}}{Percentage return for 5 days previous}
    \item{\code{Volume}}{Volume of shares traded (number of daily shares
    traded in billions)}
    \item{\code{Today}}{Percentage return for today}
    \item{\code{Direction}}{A factor with levels \code{Down} and
      \code{Up} indicating whether the market had a positive or negative
    return on a given day}
  }
}
\source{Raw values of the S&P 500 were obtained from Yahoo Finance and
  then converted to percentages and lagged.
%%  ~~ reference to a publication or URL from which the data were obtained ~~
}
\references{
  James, G., Witten, D., Hastie, T., and Tibshirani, R. (2013)
  \emph{An Introduction to Statistical Learning with applications in R},
  \url{www.StatLearning.com},
  Springer-Verlag, New York
}
\examples{
summary(Smarket)
lm(Today~Lag1+Lag2,data=Smarket)
}
\keyword{datasets}
