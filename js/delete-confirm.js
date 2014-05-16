( function( $ ){
  Drupal.behaviors.addressbookDeleteConfirm = {
    attach: function (context, settings) {
      if (context == document) {

        $links = $('.addressbook-delete-contact');
        
        $links.bind('click', function (e) {
          var response = confirm('Do you really want to delete this contact?');
          if (!response) {
            e.preventDefault();
            return false;                        
          }
        });

      } /* close context */
    } /* close attach */
  } /* close behavior */
})( jQuery );