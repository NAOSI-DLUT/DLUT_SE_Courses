\name{Weekly}
\alias{Weekly}
\docType{data}
\title{Weekly S&P Stock Market Data
%%   ~~ data name/kind ... ~~
}
\description{Weekly percentage returns for the S&P 500 stock index
  between 1990 and 2010. 
%%  ~~ A concise (1-5 lines) description of the dataset. ~~
}
\usage{Weekly}
\format{
  A data frame with 1089 observations on the following 9 variables.
  \describe{
    \item{\code{Year}}{The year that the observation was recorded}
    \item{\code{Lag1}}{Percentage return for previous week}
    \item{\code{Lag2}}{Percentage return for 2 weeks previous}
    \item{\code{Lag3}}{Percentage return for 3 weeks previous}
    \item{\code{Lag4}}{Percentage return for 4 weeks previous}
    \item{\code{Lag5}}{Percentage return for 5 weeks previous}
    \item{\code{Volume}}{Volume of shares traded (average number of daily shares
    traded in billions)}
    \item{\code{Today}}{Percentage return for this week}
    \item{\code{Direction}}{A factor with levels \code{Down} and
      \code{Up} indicating whether the market had a positive or negative
    return on a given week}
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
summary(Weekly)
lm(Today~Lag1+Lag2,data=Weekly)
}
\keyword{datasets}
