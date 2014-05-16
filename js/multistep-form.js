( function( $ ){
  Drupal.behaviors.addressbookMultistepForm = {
    attach: function (context, settings) {
      
      if (context == document) {

        $next = $('fieldset.addressbook-form-step .addressbook-next-step'); /* next button */
        $prev = $('fieldset.addressbook-form-step .addressbook-prev-step'); /* prev button */
        $active = $('fieldset.addressbook-form-step-active'); /* active fieldset */
      
        $next.bind('click', function (e) {
          if ($active.next('.addressbook-form-step').length) {
            $active.removeClass('addressbook-form-step-active');
            $active = $active.next().addClass('addressbook-form-step-active');
          }
          e.preventDefault();
          return false;
        });

        $prev.bind('click', function (e) {
          if ($active.prev('.addressbook-form-step').length) {
            $active.removeClass('addressbook-form-step-active');
            $active = $active.prev().addClass('addressbook-form-step-active');
          }
          e.preventDefault();
          return false;
        });

      } /* close context */

    } /* close attach */
  } /* close behavior */
})( jQuery );