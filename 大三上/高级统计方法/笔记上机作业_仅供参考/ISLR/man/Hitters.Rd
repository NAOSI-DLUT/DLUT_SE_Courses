\name{Hitters}
\alias{Hitters}
\docType{data}
\title{Baseball Data
%%   ~~ data name/kind ... ~~
}
\description{Major League Baseball Data from the 1986 and 1987 seasons.
%%  ~~ A concise (1-5 lines) description of the dataset. ~~
}
\usage{Hitters}
\format{
  A data frame with 322 observations of major league players on the following 20 variables.
  \describe{
    \item{\code{AtBat}}{Number of times at bat in 1986}
    \item{\code{Hits}}{Number of hits in 1986}
    \item{\code{HmRun}}{Number of home runs in 1986}
    \item{\code{Runs}}{Number of runs in 1986}
    \item{\code{RBI}}{Number of runs batted in in 1986}
    \item{\code{Walks}}{Number of walks in 1986}
    \item{\code{Years}}{Number of years in the major leagues}
    \item{\code{CAtBat}}{Number of times at bat during his career}
    \item{\code{CHits}}{Number of hits during his career}
    \item{\code{CHmRun}}{Number of home runs during his career}
    \item{\code{CRuns}}{Number of runs during his career}
    \item{\code{CRBI}}{Number of runs batted in during his career}
    \item{\code{CWalks}}{Number of walks during his career}
    \item{\code{League}}{A factor with levels \code{A} and \code{N}
      indicating player's league at the end of 1986}
    \item{\code{Division}}{A factor with levels \code{E} and \code{W}
      indicating player's division at the end of 1986}
    \item{\code{PutOuts}}{Number of put outs in 1986}
    \item{\code{Assists}}{Number of assists in 1986}
    \item{\code{Errors}}{Number of errors in 1986}
    \item{\code{Salary}}{1987 annual salary on opening day in thousands of  dollars}
    \item{\code{NewLeague}}{A factor with levels \code{A} and \code{N}
      indicating player's league at the beginning of 1987}
  }
}
\source{This dataset was taken from the StatLib library which is
  maintained at Carnegie Mellon University. This is part of the data
  that was used in the 1988 ASA Graphics Section Poster Session. The
  salary data  were  originally  from  Sports Illustrated, April 20,
  1987. The 1986 and career statistics were obtained from The 1987 Baseball
  Encyclopedia Update published by Collier  Books,  Macmillan
  Publishing  Company, New York. 
%%  ~~ reference to a publication or URL from which the data were obtained ~~
}
\references{
  James, G., Witten, D., Hastie, T., and Tibshirani, R. (2013)
  \emph{An Introduction to Statistical Learning with applications in R},
  \url{www.StatLearning.com},
  Springer-Verlag, New York
}
\examples{
summary(Hitters)
lm(Salary~AtBat+Hits,data=Hitters)
}
\keyword{datasets}
