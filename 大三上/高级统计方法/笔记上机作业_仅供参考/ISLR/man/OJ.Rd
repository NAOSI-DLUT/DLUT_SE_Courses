\name{OJ}
\alias{OJ}
\docType{data}
\title{Orange Juice Data
%%   ~~ data name/kind ... ~~
}
\description{The data contains 1070 purchases where the customer either
  purchased Citrus Hill or Minute Maid Orange Juice. A number of
  characteristics of the customer and product are recorded.
%%  ~~ A concise (1-5 lines) description of the dataset. ~~
}
\usage{OJ}
\format{
  A data frame with 1070 observations on the following 18 variables.
  \describe{
    \item{\code{Purchase}}{A factor with levels \code{CH} and \code{MM}
      indicating whether the customer purchased Citrus Hill or Minute
      Maid Orange Juice}
%    \item{\code{HouseholdID}}{Household ID}
    \item{\code{WeekofPurchase}}{Week of purchase}
    \item{\code{StoreID}}{Store ID}
 %   \item{\code{Buy}}{0/1 dummy variable where 1 corresponds to CH purchase}
    \item{\code{PriceCH}}{Price charged for CH}
    \item{\code{PriceMM}}{Price charged for MM}
    \item{\code{DiscCH}}{Discount offered for CH}
    \item{\code{DiscMM}}{Discount offered for MM}
    \item{\code{SpecialCH}}{Indicator of special on CH}
    \item{\code{SpecialMM}}{Indicator of special on MM}
    \item{\code{LoyalCH}}{Customer brand loyalty for CH}
%    \item{\code{LoyalMM}}{Customer brand loyalty for MM}
    \item{\code{SalePriceMM}}{Sale price for MM}
    \item{\code{SalePriceCH}}{Sale price for CH}
    \item{\code{PriceDiff}}{Sale price of MM less sale price of CH}
    \item{\code{Store7}}{A factor with levels \code{No} and \code{Yes}
      indicating whether the sale is at Store 7}
    \item{\code{PctDiscMM}}{Percentage discount for MM}
    \item{\code{PctDiscCH}}{Percentage discount for CH}
    \item{\code{ListPriceDiff}}{List price of MM less list price of CH}
    \item{\code{STORE}}{Which of 5 possible stores the sale occured at}
  }
}
\source{Stine, Robert A., Foster, Dean P., Waterman, Richard P. Business
  Analysis Using Regression (1998). Published by Springer. 
%%  ~~ reference to a publication or URL from which the data were obtained ~~
}
\references{
  James, G., Witten, D., Hastie, T., and Tibshirani, R. (2013)
  \emph{An Introduction to Statistical Learning with applications in R},
  \url{www.StatLearning.com},
  Springer-Verlag, New York
}
\examples{
summary(OJ)
plot(OJ$Purchase,OJ$PriceCH)
}
\keyword{datasets}
